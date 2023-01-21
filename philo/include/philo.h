/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:39:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/21 16:59:23 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

enum e_hand
{
	left,
	right,
	forky,
	eat,
	sleepy,
	think,
	dead
};

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				nbr_of_meals_taken;
	int				l_h;
	int				r_h;
	long			time_of_last_meal;
	long			*start_time;
	pthread_mutex_t	*my_hashi;
	struct s_philo	*next_philo;
	struct s_info	*data;
}		t_philo;

typedef struct s_info
{
	int				nbr_of_philos;
	int				time_to_die;
	int				nbr_of_meals;
	int				dead;
	int				sbdy_full;
	long			start_time;

	pthread_mutex_t	*all_hashi;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	check_dead;
	pthread_t		*threads;
	pthread_t		monitor;
	t_philo			*all_philos;

}		t_info;

// Common.c
long	get_time();
long	time_now(t_philo *philo);
int		ft_atoi(char *str);
int		ft_isnum(char *str);
void	smart_sleep(long time, t_philo *philo);
void	throw_msg(t_philo *philo, enum e_hand hand);

// main.c
void	init(t_info *data, char **argv);
void	quit(t_info *data);

// print_color
int		print_red(char *str);
int		print_yellow(char *str);
int		print_cyan(char *str);
int		print_green(char *str);
int		print_usage(void);

// Routine
void	*routine(void *data);
void	*monitoring(void *args);
int		check_stop(t_philo *philo);

// Actions
int		taking_hashi(t_philo *philo, enum e_hand hand);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
#endif
