/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:39:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/10 15:10:58 by gusousa          ###   ########.fr       */
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
	int				total_nbr_of_meals;
	int				nbr_of_meals_taken;
	int				stop;
	long			time_of_last_meal;
	long			start_time;
	//long			limit_of_life;
	struct s_info	*data;
}		t_philo;

typedef struct	s_info
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				nbr_time_must_eat;

	int				dead;

	pthread_mutex_t	*hashi;
	pthread_mutex_t	lock_print;
	pthread_t		*threads;
	pthread_t		monitor;
	t_philo			*all_philos;

}		t_info;

// Common.c
long	get_time(void);
int		ft_atoi(char *str);
int		ft_isnum(char *str);

// Inits
void	init(t_info *data);

// ends
void	end_mutex(t_info *data);
void	end_threads(t_info *data);
void	quit(t_info *data);

// print_color
int		print_red(char *str);
int		print_yellow(char *str);
int		print_white(char *str);
int		print_green(char *str);
int		print_usage(void);

// Routine
void	*routine(void *data);
void	*monitoring(void *data);

// Actions
void	taking_hashi(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
#endif
