/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 17:29:41 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_info *data)
{
	int		i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(&data->hashi[i], NULL);
	pthread_mutex_init(&data->lock_print, NULL);
}

void	init_philosophers(t_info *data)
{
	int		i;

	i = -1;
	while (++i < data->nbr_of_philos)
	{
		data->all_philos[i].id = i;
		data->all_philos[i].data = data;
		data->all_philos[i].total_nbr_of_meals = 0;
		data->all_philos[i].stop = 0;
		data->all_philos[i].start_time = 0;
	}
}

void	init_threads(t_info *data)
{
	int			i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_create(data->threads, NULL, routine, (data)->all_philos + i);
	pthread_create(&data->monitor, NULL, monitoring, data);
	i = -1;
}

void	init(t_info *data)
{
	data->hashi = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
	data->all_philos = malloc(data->nbr_of_philos * sizeof(t_philo));
	data->threads = malloc(data->nbr_of_philos * sizeof(pthread_t));
	data->monitor = malloc(data->nbr_of_philos * sizeof(pthread_t));
	init_mutex(data);
	init_philosophers(data);
	init_threads(data);
}
