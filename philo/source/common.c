/*
*  ** Returns the timestamp in milliseconds.
*   */
long	get_time(void)
{
	struct timeval	tp;
	long	milliseconds;

	gettimeofday(&tp, NULL); //what is second argument?
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

int	throw_error(char *error)
{
	printf("\033[0;31m\n");// Colocar em um e_num ou macro?
	printf("Error\n%s\n", error);
	printf("\033[0ms");
}
