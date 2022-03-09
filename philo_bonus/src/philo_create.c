/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 21:58:19 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_died(t_philosopher *ph)
{
	bool	run;

	pthread_mutex_lock(&ph->philo->mutex_running);
	run = ph->philo->running;
	ph->philo->running = false;
	pthread_mutex_unlock(&ph->philo->mutex_running);
	if (run == true)
		printf(GRAY"%d %s \033[1;36m%3d  %s\n\033[1;37m",
			gettimediff((struct timeval *)&ph->philo->start_dinner),
			"ms", ph->id, RED"has died");
	return (NULL);
}

void	*routine_limited(void *arg)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)arg;
	while (ph->ntimes2eat > 0)
	{
		if (ph->state == THINKING)
			philo_eat(ph);
		if (ph->state == SLEEPING && ph->ntimes2eat > 0)
		{
			if (print_time_msg(ph, BLUE"is sleeping") == false)
				return (NULL);
			ph->state = SLEEPING;
			time_countdown(ph, ph->philo->time2sleep);
			if (print_time_msg(ph, PINK"is thinking") == false)
				return (NULL);
			ph->state = THINKING;
		}
		if (ph->state == DIED)
			return (philo_died(ph));
	}
	return (ph);
}

void	*routine_unlimited(void *arg)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)arg;
	while (1)
	{
		if (ph->state == THINKING)
			philo_eat(ph);
		if (ph->state == SLEEPING)
		{
			if (print_time_msg(ph, BLUE"is sleeping") == false)
				return (NULL);
			ph->state = SLEEPING;
			time_countdown(ph, ph->philo->time2sleep);
			if (print_time_msg(ph, PINK"is thinking") == false)
				return (NULL);
			ph->state = THINKING;
		}
		if (ph->state == DIED)
			return (philo_died(ph));
	}
	return (ph);
}

int	philo_create(t_philo *philo)
{
	int	i;

	gettimeofday((struct timeval *)&philo->start_dinner, NULL);
	i = 0;
	while (i < philo->nphs)
	{
		if (philo->infinity)
		{
			if (pthread_create(philo->phs[i].thr, NULL, &routine_unlimited,
					(void *)&philo->phs[i]) != 0)
				return (error_msg("Error: Failed to create pthread\n"));
		}
		else
		{
			if (pthread_create(philo->phs[i].thr, NULL, &routine_limited,
					(void *)&philo->phs[i]) != 0)
				return (error_msg("Error: Failed to create pthread\n"));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
