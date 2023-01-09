/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 17:02:04 by gusousa          ###   ########.fr       */
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

int	print_cyan(char *str)
{
	printf("\033[0;36m");
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
	print_red(" ________________________________________________ \n");
	print_red("|          Please enter 4 or 5 arguments         |\n");
	print_red("|________________________________________________|\n");
	print_red("|           [1][Number of philosophers]          |\n");
	print_red("|           [2][Time to die]                     |\n");
	print_red("|           [3][Time to eat]                     |\n");
	print_red("|           [4][Time to sleep]                   |\n");
	print_red("|           [5][Number of meals]                 |\n");
	print_red("|________________________________________________|\n");
	return (1);
}
