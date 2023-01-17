/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/17 15:40:37 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_red(char *str)
{
	printf("\033[1;31m");
	printf("%s", str);
	printf("\033[0m\n");
	return (1);
}

int	print_yellow(char *str)
{
	printf("\033[0;33m");
	printf("%s", str);
	printf("\033[0m\n");
	return (1);
}

int	print_cyan(char *str)
{
	printf("\033[0;36m");
	printf("%s", str);
	printf("\033[0m\n");
	return (1);
}

int	print_green(char *str)
{
	printf("\033[0;32m");
	printf("%s", str);
	printf("\033[0m\n");
	return (1);
}

int	print_usage(void)
{
	print_red(" ________________________________________________ ");
	print_red("|          Please enter 4 or 5 arguments         |");
	print_red("|           (only non-signal intergers)          |");
	print_red("|________________________________________________|");
	print_red("|           [1][Number of philosophers]          |");
	print_red("|           [2][Time to die]                     |");
	print_red("|           [3][Time to eat]                     |");
	print_red("|           [4][Time to sleep]                   |");
	print_red("|           [5][Number of meals]                 |");
	print_red("|________________________________________________|");
	return (1);
}
