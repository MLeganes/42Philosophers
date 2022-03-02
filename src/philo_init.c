/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:53 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/02 16:33:01 by amorcill         ###   ########.fr       */
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
		philo->phs[i].id = i + 1;
		philo->phs[i].state = NOSTATUS;
		philo->phs[i].ts_take_fork = 0;
		philo->phs[i].ts_eating = 0;
		philo->phs[i].ts_sleeping = 0;
		philo->phs[i].ts_thinking = 0;
		philo->phs[i].ts_died = 0;
		philo->phs[i].time2die = philo->time2die;
		philo->phs[i].time2eat = philo->time2eat;
		philo->phs[i].time2sleep = philo->time2sleep;
		philo->phs[i].ntimes2eat = philo->ntimes2eat;
		i++;
	}
	return (EXIT_SUCCESS);
}