/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/12 12:49:24 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eat_meal_to_full(t_philo *philo)
{
	(void)philo;
	return (0);
}

int	check_death(t_philo philo)
{
	(void)philo;
	return (1);
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
		// Criar ft check_deaf, dando mutex na flag dead.
		if (philo->data->dead || philo->stop || eat_meal_to_full(philo))
			return (NULL);
		taking_hashi(philo);
		if (philo->data->dead || philo->stop || eat_meal_to_full(philo))
			return (NULL);
		eating(philo);
		if (philo->data->dead || philo->stop || eat_meal_to_full(philo))
			return (NULL);
		sleeping(philo);
		if (philo->data->dead || philo->stop || eat_meal_to_full(philo))
			return (NULL);
		thinking(philo);
		if (philo->data->dead || philo->stop || eat_meal_to_full(philo))
			return (NULL);
	}
	return (NULL);
}

void	*monitoring(void *data)
{
	(void)data;
	return (NULL);
}
