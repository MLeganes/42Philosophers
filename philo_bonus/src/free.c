/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:21:55 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/10 19:46:17 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo_bonus.h"

void	free_mem(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphs)
	{
		//pthread_mutex_destroy(&philo->phs[i].mutex_l_fork);
		sem_close(philo->phs[i].sem_l_fork);
		i++;
	}
	// pthread_mutex_destroy(&philo->mutex_print);
	// pthread_mutex_destroy(&philo->mutex_running);
	sem_unlink("sem_l_fork");
	sem_close(philo->sem_print);
	sem_unlink("sem_print");
	sem_close(philo->sem_running);
	sem_unlink("sem_running");
	i = 0;
	while (i < philo->nphs)
	{
		free(philo->phs[i].thr);
		i++;
	}
	free(philo->phs);
}
