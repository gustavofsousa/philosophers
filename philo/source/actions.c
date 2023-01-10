/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/10 15:04:12 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	taking_hashi(t_philo *philo)
{

	if (philo->id % 2 == 0)
		usleep(100);
		pthread_mutex_lock(philo->right_hashi);
		pthread_mutex_lock(philo->left_hashi);
		pthread_mutex_lock(philo->data->lock_print);
		print_yellow("%l\t", get_time() - philo->start_time);
		print_yellow("%d Has taken a hashi\n", philo->id);
		print_yellow("%l\t", get_time() - philo->start_time);
		print_yellow("%d Has taken a hashi\n", philo->id);
		pthread_mutex_lock(philo->data->lock_print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_print);
	print_red("%l\t", get_time() - philo->start_time);
	print_red("%d is eating\n", philo->id);
	pthread_mutex_unlock(philo->data->lock_print);

	philo->nbr_of_meals_taken++;
	philo->time_of_last_meal = get_time();
	usleep(philo->time_to_eat);

	pthread_mutex_unlock(philo->right_hashi);
	pthread_mutex_unlock(philo->left_hashi);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_print);
	print_green("%l\t", get_time() - philo->start_time);
	print_green("%d is sleeping\n", philo->id);
	pthread_mutex_lock(philo->data->lock_print);
	usleep(philo->time_to_sleep);

}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_print);
	print_cyan("%l\t", get_time() - philo->start_time);
	print_cyan("%d is thinking\n", philo->id);
	pthread_mutex_lock(philo->data->lock_print);
}
