/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 11:21:59 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_red(char *str)
{
	printf("\033[1;31m");
	printf("%s", str);
	printf("\033[0m");
	return (1);
}

int	print_yellow(char *str)
{
	printf("\033[0;33m");
	printf("%s", str);
	printf("\033[0m");
	return (1);
}

/*
int	print_cyan(char *str)
{
	printf("\033[0;36m");
	printf("%s", str);
	printf("\033[0m");
	return (1);
}
*/

int	print_white(char *str)
{
	printf("\033[0;37m");
	printf("%s", str);
	printf("\033[0m");
	return (1);
}

int	print_green(char *str)
{
	printf("\033[0;32m");
	printf("%s", str);
	printf("\033[0m");
	return (1);
}

int	print_usage(void)
{
	printf_white(" ________________________________________________ \n");
	printf_white("|          Please enter 4 or 5 arguments         |\n");
	printf_white("|________________________________________________|\n");
	printf_white("|           [1][Number of philosophers]          |\n");
	printf_white("|           [2][Time to die]                     |\n");
	printf_white("|           [3][Time to eat]                     |\n");
	printf_white("|           [4][Time to sleep]                   |\n");
	printf_white("|           [5][Number of meals]                 |\n");
	printf_white("|________________________________________________|\n");
	return (1);
}
