/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/17 14:10:16 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	taking_hashi(t_philo *philo)
{
	pthread_mutex_lock(philo->my_hashi);
	pthread_mutex_lock(philo->next_philo->my_hashi);
	pthread_mutex_lock(&philo->data->lock_print);
	if (!philo->data->dead)
	{
		printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
		print_yellow("Has taken a hashi");
		printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
		print_yellow("Has taken a hashi");
	}
	pthread_mutex_unlock(&philo->data->lock_print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_red("is eating");
	pthread_mutex_unlock(&philo->data->lock_print);

	philo->nbr_of_meals_taken++;
	philo->time_of_last_meal = get_time();
	usleep(philo->time_to_eat * 1000);

	pthread_mutex_unlock(philo->my_hashi);
	pthread_mutex_unlock(philo->next_philo->my_hashi);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_green("is sleeping");
	pthread_mutex_unlock(&philo->data->lock_print);
	usleep(philo->time_to_sleep * 1000);

}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_cyan("is thinking");
	pthread_mutex_unlock(&philo->data->lock_print);
}
