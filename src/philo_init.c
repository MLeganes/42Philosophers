/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:53 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:31:01 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philosopher_new(int i, t_philosopher *ph, t_philo *philo)
{
	ph->id = i + 1;
	if ((i % 2) == 0)
		ph->state = THINKING;
	else
		ph->state = SLEEPING;
	ph->hasfork = false;
	ph->philo = philo;
	ph->next = NULL;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
}

int	philo_init(t_philo *philo)
{
	int	i;

	philo->phs = (t_philosopher *)malloc(sizeof(t_philosopher) * philo->nphs);
	if (philo->phs == NULL)
		return (error_msg("Error: malloc not correct\n"));
	i = 0;
	while (i < philo->nphs)
	{	
		philo->phs[i].thr = (pthread_t *)malloc(sizeof(pthread_t));
		if (philo->phs[i].thr == NULL)
			return (error_msg("Error: Failed to allocate mem for thread"));
		philosopher_new(i, &philo->phs[i], philo);
		i++;
	}
	if (philo->nphs > 1)
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
