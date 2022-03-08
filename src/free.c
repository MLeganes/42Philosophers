/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:21:55 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/07 15:26:46 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mem(t_philo *philo)
{
	int i;

	// destroy mutex
	i = 0;
	while (i < philo->nphs)
	{
		pthread_mutex_destroy(&philo->phs[i].mutex_l_fork);
		i++;
	}
	
	// Free pthreads
	i = 0;
	while (i < philo->nphs)
	{
		free(philo->phs[i].thr);
		i++;
	}
	// Free t_philosophers
	free(philo->phs);
	
}
