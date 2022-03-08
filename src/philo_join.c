/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:00:43 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/06 03:05:45 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_join(t_philo *philo)
{
	int i;
	void *result;

	i = 0;
	while(i < philo->nphs)
	{
		pthread_join(*(philo->phs[i].thr), &result);
		printf("Thread %d returned\n", i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}