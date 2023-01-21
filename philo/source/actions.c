	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2023/01/09 17:33:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 17:08:23 by gusousa          ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "../include/philo.h"

int	taking_hashi(t_philo *philo, enum e_hand hand)
{
	if (hand == left)
		pthread_mutex_lock(philo->my_hashi);
	else if (hand == right)
		pthread_mutex_lock(philo->next_philo->my_hashi);
	throw_msg(philo, forky);
	return (1);
}

void	eating(t_philo *philo)
{
	throw_msg(philo, eat);
	smart_sleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->my_hashi);
	philo->l_h = 0;
	pthread_mutex_unlock(philo->next_philo->my_hashi);
	philo->r_h = 0;
}

void	sleeping(t_philo *philo)
{
	throw_msg(philo, sleepy);
	smart_sleep(philo->time_to_sleep, philo);
}

void	thinking(t_philo *philo)
{
	throw_msg(philo, think);
}
