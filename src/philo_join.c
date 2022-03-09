/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:00:43 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:56:47 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_join(t_philo *philo)
{
	int		i;
	void	*result;

	i = 0;
	while (i < philo->nphs)
	{
		pthread_join(*(philo->phs[i].thr), &result);
		i++;
	}
	return (EXIT_SUCCESS);
}
