/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/11 16:31:04 by gusousa          ###   ########.fr       */
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
}

void	init_philosophers(t_info *data, char **argv)
{
	int		i;
	int		next_i;
	struct s_philo	**my_ph;

	i = -1;
	while (++i < data->nbr_of_philos)
	{
		**my_ph = *((data)->all_philos + i);

		*(my_ph->id) = i + 1;
		*my_ph->limit_of_life = ft_atoi(argv[2]);
		*my_ph->time_to_eat = ft_atoi(argv[3]);
		*my_ph->time_to_sleep = ft_atoi(argv[4]);
		
		*my_ph->nbr_of_meals = data->nbr_of_meals;
		*my_ph->nbr_of_meals_taken = 0;
		*my_ph->stop = 0;
	*
		*my_ph->my_hashi = &data->all_hashi[i];
		*my_ph->data = data;
	}
	i = -1;
	while (++i < data->nbr_of_philos)
	{
		next_i = (i + 1) % data->nbr_of_philos;
		(my_ph)->next_philo = &data->all_philos[next_i];
	}
}

void	init_threads(t_info *data)
{
	int			i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_create(data->threads, NULL, routine, (data)->all_philos + i);
	//pthread_create(&data->monitor, NULL, monitoring, data);
	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_join(data->threads[i], NULL);
}

void	init(t_info *data, char **argv)
{
	data->all_hashi = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
	data->all_philos = malloc(data->nbr_of_philos * sizeof(t_philo));
	data->threads = malloc(data->nbr_of_philos * sizeof(pthread_t));
	data->monitor = malloc(data->nbr_of_philos * sizeof(pthread_t));
	init_mutex(data);
	init_philosophers(data, argv);
	init_threads(data);
}
