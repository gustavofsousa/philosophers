
#include "../include/philo.h"

void	destroy_mutex(t_info *data)
{
	int	nbr_ph;

	nbr_ph = data->nbr_of_philos;
	while (nbr_ph--)
		pthread_mutex_destroy(&data->all_hashi[nbr_ph]);
	pthread_mutex_destroy(&(*data).lock_print);
	pthread_mutex_destroy(&(*data).check_dead);
}

void	free_all(t_info *data)
{
	//free(data);
	free(data->all_philos);
	free(data->all_hashi);
	free(data->threads);
	//free(&data->monitor);

}

void	quit(t_info *data)
{
	free_all(data);
	destroy_mutex(data);
}

