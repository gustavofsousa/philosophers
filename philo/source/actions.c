/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/11 14:04:24 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Se for impar, pegar o da direita
// Se for par, fazer duplinha dos filosófos
// E para o ultimo pegar o primeiro, (philo->id + 1) % total_philo
// Ter um else quando eu acho o númeor par
//
void	taking_hashi(t_philo *philo)
{

	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(philo->my_hashi);
	pthread_mutex_lock(philo->next_philo->my_hashi);
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_yellow("Has taken a hashi\n");
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_yellow("Has taken a hashi\n");
	pthread_mutex_lock(&philo->data->lock_print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_red("is eating\n");
	pthread_mutex_unlock(&philo->data->lock_print);

	philo->nbr_of_meals_taken++;
	philo->time_of_last_meal = get_time();
	usleep(philo->time_to_eat);

	pthread_mutex_unlock(philo->my_hashi);
	pthread_mutex_unlock(philo->right_hashi);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_green("is sleeping\n");
	pthread_mutex_lock(&philo->data->lock_print);
	usleep(philo->time_to_sleep);

}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld\t%d ", get_time() - philo->start_time, philo->id);
	print_cyan("is thinking\n");
	pthread_mutex_lock(&philo->data->lock_print);
}
