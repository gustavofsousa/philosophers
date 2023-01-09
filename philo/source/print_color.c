/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2023/01/09 11:04:29 by gusousa          ###   ########.fr       */
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
