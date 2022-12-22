/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:43:14 by gusousa           #+#    #+#             */
/*   Updated: 2022/12/13 18:49:07 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	receive_args(t_infor *data, int argc, char **argv)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = 0;
	if (argc == 6)
		data->nbr_of_meals = ft_atoi(argv[5]);
	if (data->nbr_philo < 2)
		return (0);
	return (1);
}

int	check_args(int argc, int argv)
{

}

int	main(int argc, char **argv)
{
	t_info	data;

	memset(&data, 0, sizeof(t_info));
	if (!check_args(argc, argv))
		return (throw_error("'Tis expected 4 or 5 arguments integers"));
	if (!receive_args(&data, argc, argv))
		return (throw_error("'Tis necessary at least 2 philosophers"));
	init_mutex(&data);
	init_philosophers(&data);
	init_threds(&data);
	end_threads(&data);
	end_mutex(&data);
	quit(&data);
	return (0);
}
