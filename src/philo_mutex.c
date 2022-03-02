/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:32:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/02 15:52:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_mutex(t_philo *philo)
{
	int i;
	int x;
	pthread_mutex_t ll;
	pthread_mutex_t *rr;
	i = 0;
	while(i < philo->nphs)
	{
		pthread_mutex_init(&philo->phs[i].left_fork, NULL);
		i++;
	}
	// link the Right fork pointer.
	i = 0;
	while (i < philo->nphs)
	{
		x = (i + 1) % 2;
		//Update right-fork-pointer from the next philosopher.
		rr = philo->phs[i].right_fork ;
		ll = philo->phs[x].left_fork;
		
		//philo->phs[i].right_fork = (pthread_mutex_t *)ll;
		(void)rr;
		(void)ll;
		
		i++;
	}
	
	return (EXIT_SUCCESS);
}