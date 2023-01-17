/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/17 10:02:36 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eat_meal_to_full(t_philo *philo)
{
	if (philo->nbr_of_meals != -1)
	{
		if (philo->nbr_of_meals_taken >= philo->nbr_of_meals)
		{
			philo->data->sbdy_full = 1;
			return (1);
		}
	}
	return (0);
}

int	check_stop(t_philo *philo)
{
	if (philo->data->dead || philo->data->sbdy_full)
			//eat_meal_to_full(philo))
		return (1);
	return (0);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;

	philo->time_of_last_meal = get_time();
	philo->start_time = get_time();
	if (philo->id % 2 == 0)
		usleep(100);
	while (!philo->data->dead)
	{
		// Quando morrer precisa largar os garfos.
		if (check_stop(philo))
			return (NULL);
		taking_hashi(philo);
		if (check_stop(philo))
			return (NULL);
		eating(philo);
		if (check_stop(philo))
			return (NULL);
		sleeping(philo);
		if (check_stop(philo))
			return (NULL);
		thinking(philo);
		if (check_stop(philo))
			return (NULL);
	}
	return (NULL);
}

// Com 1 por 1 pode perder o tempo se tiver muito filósofos.
void	*monitoring(void *args)
{
	int	i;
	long	time_since_lm;
	long	actual_time;
	t_info	*data;

	data = (t_info *)args;
	i = -1;
	while (42)
	{
		i = (i + 1) % data->nbr_of_philos;
		time_since_lm = get_time() - data->all_philos[i].time_of_last_meal;
		if (time_since_lm >= data->time_to_die)
		{
			pthread_mutex_lock(&data->lock_print);
			actual_time = get_time() - data->all_philos[i].start_time;
			printf("%ld\t%d has died\n",  actual_time, data->all_philos[i].id);
			data->dead = 1;
			pthread_mutex_unlock(&data->lock_print);
			return (NULL);
		}
		// if (full)
			//return (void *);
	}
	return (NULL);
}
