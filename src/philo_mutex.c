/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:32:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:46:04 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphs)
	{
		if (pthread_mutex_init(&philo->phs[i].mutex_l_fork, NULL) != 0)
			return (error_msg("Error: Failed to initialize mutex\n"));
		i++;
	}
	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].mutex_r_fork
				= &philo->phs[((i + 1) % philo->nphs)].mutex_l_fork;
			i++;
		}
	}
	if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
		return (error_msg("Error: Failed to initialize mutex\n"));
	if (pthread_mutex_init(&philo->mutex_running, NULL) != 0)
		return (error_msg("Error: Failed to initialize mutex\n"));
	return (EXIT_SUCCESS);
}
