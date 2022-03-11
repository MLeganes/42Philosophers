/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:56:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/11 13:48:27 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fork_takeone(t_philosopher *ph, pthread_mutex_t *mut)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mut);
	if (ph->hasfork == false)
	{
		ph->hasfork = true;
		ret = true;
	}
	pthread_mutex_unlock(mut);
	return (ret);
}

static int	philo_takefork(t_philosopher *ph, pthread_mutex_t *mut)
{
	long	time_eating;

	if (ph == NULL || mut == NULL)
		return (false);
	time_eating = ph->start_eating.tv_sec * 1000
		+ ph->start_eating.tv_usec / 1000;
	while (fork_takeone(ph, mut) == false)
	{
		if (time_eating + ph->philo->time2die < gettime())
		{
			ph->state = DIED;
			return (false);
		}
	}
	return (true);
}

static void	fork_release(pthread_mutex_t *mut, t_philosopher *ph)
{
	pthread_mutex_lock(mut);
	ph->hasfork = false;
	pthread_mutex_unlock(mut);
}

void	philo_eat(t_philosopher *ph)
{
	if (philo_takefork(ph, &ph->mutex_l_fork) == false)
		return ;
	if (print_time_msg(ph, YELLOW"has taken a fork") == false)
		return ;
	if (philo_takefork(ph->next, ph->mutex_r_fork) == false)
		return ;
	if (print_time_msg(ph, YELLOW"has taken a fork") == false)
		return ;
	if (print_time_msg(ph, GREEN"is eating") == false)
		return ;
	ph->state = EATING;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
	if (time_countdown(ph, ph->philo->time2eat) == DIED)
		return ;
	fork_release(&ph->mutex_l_fork, ph);
	fork_release(ph->mutex_r_fork, ph->next);
	ph->ntimes2eat--;
	ph->state = SLEEPING;
}
