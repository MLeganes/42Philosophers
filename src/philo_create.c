/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/02 21:05:01 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine_eat(void *arg)
{
	t_philosopher *ph;

	ph = (t_philosopher *)arg;
	pthread_mutex_lock(ph->left_fork)
	pthread_mutex_lock()
	
	(void)ph;
	
	return NULL;
}

int philo_create(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphs)
	{
		pthread_create(&philo->phs[i].thr_ph, NULL, routine_eat, &philo->phs[i]);
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