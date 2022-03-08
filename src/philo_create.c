/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 00:20:34 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char *char_state(int state)
{
	if (state == EATING)
		return ("eating");
	if (state == SLEEPING)
		return ("sleeping");
	if (state == THINKING)
		return ("thinking");
	if (state == DIED)
		return ("dead");
	return ("no status");
}

int fork_takeone(t_philosopher *ph, int fork)
{
	bool ret;

	ret = false;
	if (fork == LEFT)
	{
		pthread_mutex_lock(&ph->mutex_l_fork);
		if (ph->hasfork == false)
		{
			ph->hasfork = true;
			ret = true;
		}
		pthread_mutex_unlock(&ph->mutex_l_fork);
		print_time_msg(ph, YELLOW"has taken a fork");
	}
	else if (fork == RIGHT)
	{
		if (ph->mutex_r_fork && ph->next)
		{
			pthread_mutex_lock(ph->mutex_r_fork);
			if (ph->next->hasfork == false)
			{
				ph->next->hasfork = true;
				ret = true;
			}
			pthread_mutex_unlock(ph->mutex_r_fork);
			print_time_msg(ph, YELLOW"has taken a fork");
		}
	}
	return (ret);
}

void fork_releaseone(t_philosopher *ph, int fork)
{
	if (fork == LEFT)
	{
		pthread_mutex_lock(&ph->mutex_l_fork);
			ph->hasfork = false;
		pthread_mutex_unlock(&ph->mutex_l_fork);
	}
	else if (fork == RIGHT)
	{
		pthread_mutex_lock(ph->mutex_r_fork);
			ph->next->hasfork = false;
		pthread_mutex_unlock(ph->mutex_r_fork);
	}
}

int philo_takefork(t_philosopher *ph, int fork)
{
	long 	time_eating;

	time_eating = ph->start_eating.tv_sec * 1000 + ph->start_eating.tv_usec / 1000;
	while (fork_takeone(ph, fork) == false)
	{
		if ( time_eating + ph->philo->time2die < gettime())
		{
			ph->state = DIED;
			return (false);
		}
	}
	return (true);
}

void philo_eat(t_philosopher *ph)
{
	if (philo_takefork(ph, LEFT) == false || philo_takefork(ph, RIGHT) == false)
		return ;
	print_time_msg(ph, GREEN"is eating");
	
	ph->state = EATING;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
	// Call the time_countdown to do the usleep, keeping the eyee in the time-2-die.
	if (time_countdown(ph, ph->philo->time2eat) == DIED)
		return ;
	// Finished eating
	// release forks
	fork_releaseone(ph, LEFT);
	fork_releaseone(ph, RIGHT);
	ph->state = SLEEPING;	
}

/* Routine for finitive loop */
void *routine_limited(void *arg)
{
	t_philosopher *ph;
	int i;

	i = 0;
	ph = (t_philosopher *)arg;
	
	while (i < ph->philo->ntimes2eat)
	{
		if (ph->state == THINKING)
			philo_eat(ph);
		if (ph->state == SLEEPING)
		{
			
			print_time_msg(ph, BLUE"is sleeping");
			ph->state = SLEEPING;
			time_countdown(ph, ph->philo->time2sleep);
			print_time_msg(ph, PINK"is thinking");
			ph->state = THINKING;
		}
		if (ph->state == DIED)
		{
			print_time_msg(ph, RED"has died");
			free_mem(ph->philo);
			return NULL;
			// free everything
			// stop
		}
		i++;
	}
	return ph;
}

void *routine_unlimited(void *arg)
{
	(void)arg;
	return NULL;
}

int philo_create(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphs)
	{
		if (philo->infinity)
		{
			if (pthread_create(philo->phs[i].thr, NULL, &routine_unlimited, (void *)&philo->phs[i]) != 0)
				return (error_msg("Error: Failed to create pthread\n"));
			//usleep(100);
		}
		else
		{
			if (pthread_create(philo->phs[i].thr, NULL, &routine_limited, (void *)&philo->phs[i]) != 0)
				return (error_msg("Error: Failed to create pthread\n"));
			//usleep(100);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}