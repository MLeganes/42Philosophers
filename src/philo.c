/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:21:50 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/01 19:13:07 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// int beers = 2000000;
// pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

// void *drink_lots(void *a) 
// {
// 	(void)a;
// 	int i;
	
// 	pthread_mutex_lock(&beers_lock);
// 	for (i = 0; i < 100000; i++) 
// 	{
// 		beers = beers - 1; 
// 	}
// 	pthread_mutex_unlock(&beers_lock);
// 	printf("beers = %i\n", beers); 
// 	return NULL;
// }


// int main()
//  {
// 	pthread_t threads[20];
// 	int t;
// 	long l = 0;
// 	printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
	
// 	for (t = 0; t < 20; t++) 
// 	{
// 		pthread_create(&threads[t], NULL, &drink_lots, (void *)l );
// 	}
	
// 	void* result;
// 	for (t = 0; t < 20; t++)
// 	 {
// 		pthread_join(threads[t], &result);
// 	}
	
// 	printf("There are now %i bottles of beer on the wall\n", beers); 
	
// 	return 0;
// }

// static void *routine(void *param)
// {
// 	long thread_no = (long)param;
// 	printf("Test from thread no: %ld\n", thread_no);
// 	return (void *)(thread_no + 1);
// }

int main(int args, char **argv)
{
	t_philo philo;

	if ( philo_parser_arg(args, argv, &philo))
		return (EXIT_FAILURE);

	if (philo_init(&philo))
		return (EXIT_FAILURE);

	
	// void *result;
	// for (t = 0; t < 10; t++)
	// {
	// 	pthread_join(threads[t], &result);
	// 	printf("Thread returned %ld\n", (long)result);;

		
	// }

    return (0);
}