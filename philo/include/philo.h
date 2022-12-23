/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:39:39 by gusousa           #+#    #+#             */
/*   Updated: 2022/12/23 10:14:58 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_philo
{
	int				id;
	//struct s_info	data;
}		t_philo;

typedef struct	s_info
{
	int		nbr_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_time_must_eat;
	int		dead;
	int		nbr_of_meals;
	t_philo		*all_philos;

}		t_info;

// Common.c
long	get_time(void);
void	throw_error(char *error);

// Inits
void	init_mutex(t_info *data);
void	init_philosophers(t_info *data);
void	init_threads(t_info *data);

// ends
void	end_mutex(t_info *data);
void	end_threads(t_info *data);
void	quit(t_info *data);

#endif
