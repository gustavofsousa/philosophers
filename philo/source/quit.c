/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:48:32 by gustavosousa      #+#    #+#             */
/*   Updated: 2023/01/19 10:55:38 by gustavosousa     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_info *data)
{
	int	nbr_ph;

	nbr_ph = data->nbr_of_philos;
	while (nbr_ph--)
		pthread_mutex_destroy(&data->all_hashi[nbr_ph]);
	pthread_mutex_destroy(&(*data).lock_print);
	pthread_mutex_destroy(&(*data).check_dead);
}

void	free_all(t_info *data)
{
	free(data->all_philos);
	free(data->all_hashi);
	free(data->threads);
}

void	quit(t_info *data)
{
	destroy_mutex(data);
	free_all(data);
}
