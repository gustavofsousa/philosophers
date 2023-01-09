/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 11:55:00 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_info *data)
{
	int		i;

	data->hashi = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(&data->hashi[i], NULL);
	pthread_mutex_init(&data->lock_print, NULL);
}

void	init_philosophers(t_info *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(data->nbr_of_philos * sizeof(t_philo));
	while (i < data->nbr_of_philos)
	{
		philos[i].id = i;
		philos[i].data = data;
		i++;
	}
	data->all_philos = philos;
}

void	init_threads(t_info *data)
{
	int		i;

	data->threads = malloc (data->nbr_of_philos * sizeof(pthread_t));
	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_create(&data->threads, NULL, routine, data->all_philos + i);
		i++;
	}
	//pthread_create(&data->monitor, NULL, monitor, data->all_philos);
}
