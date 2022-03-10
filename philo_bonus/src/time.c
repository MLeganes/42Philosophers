/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:50:15 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/10 18:01:58 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo_bonus.h"

bool	print_time_msg(t_philosopher *philo, char *msg)
{
	int		newdiff;
	bool	ret;

	newdiff = gettimediff((struct timeval *)&philo->philo->start_dinner);
	// pthread_mutex_lock(&philo->philo->mutex_print);
	// pthread_mutex_lock(&philo->philo->mutex_running);
	sem_wait(philo->philo->sem_print);
	sem_wait(philo->philo->sem_running);
	ret = philo->philo->running;
	if (philo->philo->running)
		printf(GRAY"%d %s \033[1;36m%3d  %s\n\033[1;37m", newdiff,
			"ms", philo->id, msg);
	sem_post(philo->philo->sem_running);
	sem_post(philo->philo->sem_print);
	// pthread_mutex_unlock(&philo->philo->mutex_running);
	// pthread_mutex_unlock(&philo->philo->mutex_print);
	return (ret);
}

int	gettimediff(struct timeval *t)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - t->tv_sec) * 1000)
		+ ((now.tv_usec - t->tv_usec) / 1000));
}

long	gettime(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

t_status	time_countdown(t_philosopher *ph, int countdown)
{
	long	start;
	long	now;
	long	time_eating;

	start = gettime();
	now = start;
	time_eating = ph->start_eating.tv_sec * 1000
		+ ph->start_eating.tv_usec / 1000;
	while (now < (start + countdown))
	{
		usleep(100);
		now = gettime();
		if (time_eating + ph->philo->time2die < now)
		{
			ph->state = DIED;
			return (DIED);
		}
	}
	return (ph->state);
}
