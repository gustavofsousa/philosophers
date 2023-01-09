/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:39:39 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 11:55:24 by gusousa          ###   ########.fr       */
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
	long			last_meal;
	struct s_info	*data;
}		t_philo;

typedef struct	s_info
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_must_eat;
	int				dead;
	int				nbr_of_meals;
	pthread_mutex_t	*hashi;
	pthread_mutex	lock_print;
	pthread_t		*threads;
	t_philo			*all_philos;

}		t_info;

// Common.c
long	get_time(void);
int		ft_atoi(char *str);
int		ft_isnum(char *str);

// Inits
void	init_mutex(t_info *data);
void	init_philosophers(t_info *data);
void	init_threads(t_info *data);

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

#endif
