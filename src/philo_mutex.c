/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:32:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 18:12:59 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void printf_philosopher(t_philosopher *ph)
// {
// 	printf("<<<<<<<<<<<<<<<<<<<<<<<<DEBUGGER>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
// 	printf("Philosopher no.: %d\n", ph->id);
// 	printf("Philosopher state: %d\n", ph->state);
// 	printf("Philosopher ts to die: %d\n", ph->ts_died);
// 	printf("Philosopher ts easting: %d\n", ph->ts_eating);
// 	printf("Philosopher ts sleeping: %d\n", ph->ts_sleeping);
// 	printf("Philosopher ts take fork: %d\n", ph->ts_take_fork);
// 	printf("Philosopher ts thinking: %d\n", ph->ts_thinking);
// 	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
// }

int philo_mutex(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->nphs)
	{
		// One philosopher one fork. Left-fork.
		if (pthread_mutex_init(&philo->phs[i].mutex_l_fork, NULL) != 0)
			return (error_msg("Error: Failed to initialize mutex\n"));
		i++;
	}
	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			// Update right-fork-pointer from the next philosopher.
			// Right-fork is a pointer to next philosopher left-fork.
			philo->phs[i].mutex_r_fork  = &philo->phs[((i + 1) % philo->nphs)].mutex_l_fork;
			i++;
		}
	}
	if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
		return (error_msg("Error: Failed to initialize mutex\n"));
	if (pthread_mutex_init(&philo->mutex_running, NULL) != 0)
		return (error_msg("Error: Failed to initialize mutex\n"));
	return (EXIT_SUCCESS);
}
