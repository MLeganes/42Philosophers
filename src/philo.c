/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:21:50 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/01 11:27:07 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *routine(void *param)
{
	long thread_no = (long)param;
	printf("Test from thread no: %ld\n", thread_no);
	return (void *)(thread_no + 1);
}


int main(int args, char **argv)
{
	
    (void) args;
    (void) argv;

	pthread_t threads[20];
	long t;
	for ( t = 0; t < 10; t++)
	{
		pthread_create(&threads[t], NULL, &routine, (void *)t); //No create and init
	}
	void *result;
	for (t = 0; t < 10; t++)
	{
		pthread_join(threads[t], &result);
		printf("Thread returned %ld\n", (long)result);;

		
	}

    return (0);
}