/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:56:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/10 21:12:03 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo_bonus.h"

static int	fork_takeone(t_philosopher *ph, sem_t *sem)
{
	bool	ret;

	ret = false;
	sem_wait(sem);
	if (ph->hasfork == false)
	{
		ph->hasfork = true;
		ret = true;
	}
	sem_post(sem);
	return (ret);
}

static int	philo_takefork(t_philosopher *ph, sem_t *mut)
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

static void	fork_release(sem_t *sem, t_philosopher *ph)
{
	sem_wait(sem);
	ph->hasfork = false;
	sem_post(sem);
}

void	philo_eat(t_philosopher *ph)
{
	if (philo_takefork(ph, ph->sem_l_fork) == false)
		return ;
	if (print_time_msg(ph, YELLOW"has taken a fork") == false)
		return ;
	if (philo_takefork(ph->next, ph->sem_r_fork) == false)
		return ;
	if (print_time_msg(ph, YELLOW"has taken a fork") == false)
		return ;
	if (print_time_msg(ph, GREEN"is eating") == false)
		return ;
	ph->state = EATING;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
	if (time_countdown(ph, ph->philo->time2eat) == DIED)
		return ;
	fork_release(ph->sem_l_fork, ph);
	fork_release(ph->sem_r_fork, ph->next);
	ph->ntimes2eat--;
	ph->state = SLEEPING;
}
