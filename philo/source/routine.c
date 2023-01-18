/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/17 18:45:35 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eat_meal_to_full(t_philo *philo)
{
	if (philo->nbr_of_meals != -1)
	{
		if (philo->nbr_of_meals_taken == philo->nbr_of_meals)
		{
			philo->data->sbdy_full++;
			return (1);
		}
	}
	return (0);
}

int	check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_dead);
	if (philo->data->dead || eat_meal_to_full(philo))
	{
		pthread_mutex_unlock(&philo->data->check_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->check_dead);
	return (0);
}

void	help_yourself(t_philo *philo)
{
	while (42)
	{
		if (check_stop(philo))
			break ;
		philo->l_h = taking_hashi(philo, left);
		if (check_stop(philo))
			break ;
		philo->r_h = taking_hashi(philo, right);
		if (check_stop(philo))
			break ;
		eating(philo);
		if (check_stop(philo))
			break ;
		sleeping(philo);
		if (check_stop(philo))
			break ;
		thinking(philo);
		if (check_stop(philo))
			break ;
	}
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(100 * 1000);
	if (philo->data->nbr_of_philos == 1)
		philo->l_h = taking_hashi(philo, left);
	else
		help_yourself(philo);
	if (philo->l_h == 1)
		pthread_mutex_unlock(philo->my_hashi);
	if (philo->r_h == 1)
		pthread_mutex_unlock(philo->next_philo->my_hashi);
	return (NULL);
}

int	check_full(t_info *data)
{
	pthread_mutex_lock(&data->check_dead);
	if (data->sbdy_full < data->nbr_of_philos)
	{
		pthread_mutex_unlock(&data->check_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->check_dead);
	return (0);
}

void	*monitoring(void *args)
{
	int		i;
	long	time_since_lm;
	long	actual_time;
	t_info	*data;

	data = (t_info *)args;
	i = -1;
	while (check_full(data))
	{
		if (++i == data->nbr_of_philos)
			i = 0;
		pthread_mutex_lock(&data->lock_print);
		time_since_lm = get_time() - data->all_philos[i].time_of_last_meal;
		if (time_since_lm == data->time_to_die)
		{
			pthread_mutex_lock(&data->check_dead);
			data->dead = 1;
			pthread_mutex_unlock(&data->check_dead);
			actual_time = get_time() - *data->all_philos[i].start_time;
			printf("%ldms\t%d died\n", actual_time, data->all_philos[i].id);
			pthread_mutex_unlock(&data->lock_print);
			return (NULL);
		}
		pthread_mutex_unlock(&data->lock_print);
	}
	return (NULL);
}
