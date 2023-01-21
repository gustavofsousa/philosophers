/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 17:07:57 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


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
	t_info	*data;
	t_philo	*ph;

	data = (t_info *)args;
	ph = data->all_philos;
	i = -1;
	while (check_full(data))
	{
		if (++i == data->nbr_of_philos)
			i = 0;
		pthread_mutex_lock(&data->lock_print);
		time_since_lm = time_now(&ph[i]) - ph[i].time_of_last_meal;
		pthread_mutex_unlock(&data->lock_print);
		if (time_since_lm >= data->time_to_die)
		{
			throw_msg(&ph[i], dead);
			pthread_mutex_lock(&data->check_dead);
			data->dead = 1;
			pthread_mutex_unlock(&data->check_dead);
			break ;
		}
		smart_sleep(200, ph + i);
	}
	return (NULL);
}
