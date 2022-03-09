/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:53 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 16:52:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_init(t_philo *philo)
{
	int i;

	philo->phs = (t_philosopher *)malloc(sizeof(t_philosopher) * philo->nphs);
	if (philo->phs == NULL)
			return (error_msg("Error: malloc not correct\n"));
	i = 0;
	while (i < philo->nphs)
	{	
		philo->phs[i].thr = (pthread_t *)malloc(sizeof(pthread_t));
		if (philo->phs[i].thr == NULL)
			return (error_msg("Error: Failed to allocate mem for thread"));
		philo->phs[i].id = i + 1;
		if ((i % 2) == 0)
			philo->phs[i].state = THINKING;
		else
			philo->phs[i].state = SLEEPING;
		philo->phs[i].hasfork = false;
		// philo->phs[i].ts_take_fork = (u_int64_t)0;
		// philo->phs[i].ts_eating = (u_int64_t)0;
		// philo->phs[i].ts_sleeping = (u_int64_t)0;
		// philo->phs[i].ts_thinking = (u_int64_t)0;
		// philo->phs[i].ts_died = (u_int64_t)0;
		philo->phs[i].philo = philo;
		philo->phs[i].next = NULL;
		gettimeofday((struct timeval *)&philo->phs[i].start_eating, NULL);
		//philo->phs[i].ts_start = get_time();
	
		i++;
	}
	if(philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].next = &philo->phs[((i + 1) % philo->nphs)];
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
