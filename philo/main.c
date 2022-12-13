/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:43:14 by gusousa           #+#    #+#             */
/*   Updated: 2022/12/13 18:49:07 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 ** Returns the timestamp in milliseconds.
 */
long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL); //what is second argument?
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	long	start_time;

	// Time when we started.
	start_time = get_time();
	while (42)
	{
		printf("%ld\n", get_time() - start_time);

		usleep(200 * 1000);
	}
	return (0);
}
