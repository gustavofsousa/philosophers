/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 16:56:41 by gusousa          ###   ########.fr       */
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
		pthread_mutex_lock(&data->check_dead);
		time_since_lm = time_now(&ph[i]) - ph[i].time_of_last_meal;
		if (time_since_lm >= data->time_to_die)
		{
			data->dead = 1;
			throw_msg(&ph[i], dead);
			break ;
		}
		pthread_mutex_unlock(&data->check_dead);
		smart_sleep(200, ph + i);
	}
	return (NULL);
}
