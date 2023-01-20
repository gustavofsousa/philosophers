/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/20 10:16:05 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	taking_hashi(t_philo *philo, enum e_hand hand)
{
	if (philo->data->nbr_of_philos == 1 && hand == right)
		philo->data->dead = 1;
	if (hand == left)
		pthread_mutex_lock(philo->my_hashi);
	else if (hand == right)
		pthread_mutex_lock(philo->next_philo->my_hashi);
	pthread_mutex_lock(&philo->data->lock_print);
	if (!check_stop(philo))
	{
		printf("%ldms\t%d ", get_time() - *philo->start_time, philo->id);
		print_yellow("Has taken a fork");
	}
	pthread_mutex_unlock(&philo->data->lock_print);
	return (1);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if (!check_stop(philo))
	{
		printf("%ldms\t%d ", get_time() - *philo->start_time, philo->id);
		print_red("is eating");
	}
	philo->time_of_last_meal = get_time();
	pthread_mutex_unlock(&philo->data->lock_print);
	philo->nbr_of_meals_taken++;
	usleep(philo->time_to_eat * 1000);
	philo->l_h = 0;
	philo->r_h = 0;
	pthread_mutex_unlock(philo->my_hashi);
	pthread_mutex_unlock(philo->next_philo->my_hashi);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if (!check_stop(philo))
	{
		printf("%ldms\t%d ", get_time() - *philo->start_time, philo->id);
		print_green("is sleeping");
	}
	pthread_mutex_unlock(&philo->data->lock_print);
	usleep(philo->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if (!check_stop(philo))
	{
		printf("%ldms\t%d ", get_time() - *philo->start_time, philo->id);
		print_cyan("is thinking");
	}
	pthread_mutex_unlock(&philo->data->lock_print);
}
