/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/02 11:58:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_eat()
{
	return NULL;
}

int philo_create(t_philo *philo)
{
	int i;

	philo->phs = (t_philosopher *)malloc(sizeof(t_philosopher) * philo->nphs);

	i = 0;
	while (i < philo->nphs)
	{
		philo->phs[i].id = i + 1;
		philo->phs[i].state = NOSTATUS;
		philo->phs[i].time2die = philo->time2die;
		philo->phs[i].time2eat = philo->time2eat;
		philo->phs[i].time2sleep = philo->time2sleep;
		philo->phs[i].ntimes2eat = philo->ntimes2eat;
		
		pthread_create(&philo->phs[i].thr_ph, NULL, &routine_eat, NULL);
		i++;
	}
	
	// pthread_t threads[20];
	// long t;
	// for ( t = 0; t < 10; t++)
	// {
	// 	pthread_create(&threads[t], NULL, &routine, (void *)t); //No create and init
	// }
	return (EXIT_FAILURE);
}