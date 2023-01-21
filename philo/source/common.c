/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 16:00:19 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Get the actual time and return it.
 * The function returns the precision of time in seconds + microseconds(10^-6)
 * We convert both values to milliseconds(10^-3).
*/
long	get_time(long time_discount)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000;
	milliseconds += tv.tv_usec / 1000;
	return (milliseconds - time_discount);
}

void	smart_sleep(long time, t_philo *philo)
{
	long	start;

	(void)philo;
	start = get_time(0);
	while (get_time(0) - start <= time )
	{
	//	if (check_stop(philo))
	//		break ;
		usleep(100);
	}
}

void	throw_msg(t_philo *philo, enum e_hand hand)
{
	long	ms;

	if (check_stop(philo))
		return ;
	pthread_mutex_lock(&philo->data->lock_print);
	ms = get_time(philo->data->start_time);
	if (hand == forky)
	{
		printf("%ld\t%d has taken a fork\n", ms, philo->id);
		philo->time_of_last_meal = ms;
		philo->nbr_of_meals_taken++;
	}
	else if (hand == eat)
		printf("%ld\t%d is eating\n", ms, philo->id);
	else if (hand == sleepy)
		printf("%ld\t%d is sleeping\n", ms, philo->id);
	else if (hand == think)
		printf("%ld\t%d is thinking\n", ms, philo->id);
	pthread_mutex_unlock(&philo->data->lock_print);

}
