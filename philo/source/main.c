/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:43:14 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 11:10:10 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	receive_args(t_info *data, int argc, char **argv)
{
	data->nbr_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = 0;
	if (argc == 6)
		data->nbr_of_meals = ft_atoi(argv[5]);
	if (data->nbr_of_philos < 2)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 && argc > 6)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	data;

	memset(&data, 0, sizeof(t_info));
	if (!check_args(argc, argv))
	{
		return (print_red("Error\nUsage: ./philo <number_of_philo> <time_to_die> <time_to_eat> <time_to_sleep> [numbers_of_meals]\n"));
	}
	if (!receive_args(&data, argc, argv))
		return (print_red("Error\n\'Tis necessary at least 2 philosophers\n"));
	init_mutex(&data);
	init_philosophers(&data);
	init_threads(&data);
	end_threads(&data);
	end_mutex(&data);
	quit(&data);
	return (0);
}
