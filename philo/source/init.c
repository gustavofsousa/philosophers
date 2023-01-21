/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 18:47:23 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_info *data)
{
	int		i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(&data->all_hashi[i], NULL);
	pthread_mutex_init(&data->lock_print, NULL);
	pthread_mutex_init(&data->check_dead, NULL);
}

void	init_philosophers(t_info *data, char **argv)
{
	int		i;
	int		next_i;
	t_philo	*my_ph;

	i = -1;
	my_ph = malloc(data->nbr_of_philos * sizeof(t_philo));
	while (++i < data->nbr_of_philos)
	{
		my_ph[i].id = i + 1;
		my_ph[i].time_to_eat = ft_atoi(argv[3]);
		my_ph[i].time_to_sleep = ft_atoi(argv[4]);
		my_ph[i].nbr_of_meals = data->nbr_of_meals;
		my_ph[i].nbr_of_meals_taken = 0;
		my_ph[i].start_time = &data->start_time;
		my_ph[i].l_h = 0;
		my_ph[i].r_h = 0;
		my_ph[i].my_hashi = &data->all_hashi[i];
		my_ph[i].data = data;
		my_ph[i].time_of_last_meal = time_now(&my_ph[i]);
		next_i = (i + 1) % data->nbr_of_philos;
		my_ph[i].next_philo = &my_ph[next_i];
	}
	data->all_philos = my_ph;
}

void	init_threads(t_info *data)
{
	int			i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_create((data)->threads + i, NULL,
			routine, (data)->all_philos + i);
	pthread_create(&data->monitor, NULL, monitoring, data);
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_join(data->threads[i], NULL);
	pthread_join(data->monitor, NULL);
}

void	init(t_info *data, char **argv)
{
	data->all_hashi = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
	data->threads = malloc(data->nbr_of_philos * sizeof(pthread_t));
	init_mutex(data);
	init_philosophers(data, argv);
	init_threads(data);
}
