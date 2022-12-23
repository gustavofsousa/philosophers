/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:03:45 by gusousa           #+#    #+#             */
/*   Updated: 2022/12/23 16:33:04 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Get the actual time and return it.
 * The function returns the precision of time in seconds + microseconds(10^-6)
 * We convert both values to milliseconds(10^-3).
*/
long	get_time(void)
{
	struct timeval	tv;
	long	milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000;
	milliseconds += tv.tv_usec / 1000;
	return (milliseconds);
}

int	throw_error(char *error)
{
	printf("\033[0;31m\n");// Colocar em um e_num ou macro?
	printf("Error\n%s\n", error);
	printf("\033[0ms");
}

void	print_red(char *str)
{
	printf("\033[1;31m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_yellow(char *str)
{
	printf("\033[0;33m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_cyan(char *str)
{
	printf("\033[0;36m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_white(char *str)
{
	printf("\033[0;37m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_green(char *str)
{
	printf("\033[0;32m");
	printf("%s", str);
	printf("\033[0m");
}
