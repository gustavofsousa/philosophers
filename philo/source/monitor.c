/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:59:51 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/19 15:43:52 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*hit_and_run(t_info *data, int i)
{
	long	actual_time;

	pthread_mutex_lock(&data->check_dead);
	data->dead = 1;
	pthread_mutex_unlock(&data->check_dead);
	actual_time = get_time() - *data->all_philos[i].start_time;
	printf("%ldms\t%d died\n", actual_time, data->all_philos[i].id);
	pthread_mutex_unlock(&data->lock_print);
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
			return (hit_and_run(data, i));
		pthread_mutex_unlock(&data->lock_print);
		usleep(200);
	}
	return (NULL);
}
