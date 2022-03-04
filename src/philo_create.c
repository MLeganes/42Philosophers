/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/04 17:05:03 by amorcill         ###   ########.fr       */
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
	if (state == DEAD)
		return ("dead");
	return ("no status");
}

// void *routine_eat(void *arg)
// {
// 	t_philosopher *ph;	
// 	ph = (t_philosopher *)arg;
// 	// if (ph->isforkfree == true)
// 	// {
// 	// 	pthread_mutex_lock(&ph->mutex_l_fork);
// 	// 	if (ph->next->isforkfree == true)
// 	// 	{
// 	// 		pthread_mutex_lock(&ph->next->mutex_l_fork);
// 	// 		ph->isforkfree = false;
// 	// 		ph->next->isforkfree = false;
// 	// 		pthread_mutex_unlock(&ph->next->mutex_l_fork);
// 	// 	}
// 	// 	pthread_mutex_unlock(&ph->mutex_l_fork);
// 	// }
// 	while (1)
// 	{
// 		// take forks TO EAT.
// 		if (ph->state == THINKING)
// 		{
// 			pthread_mutex_lock(ph->mutex_r_fork);
// 			pthread_mutex_unlock(&ph->mutex_l_fork);
// 				ph->isforkfree = false;
// 				ph->next->isforkfree = false;
// 			pthread_mutex_unlock(&ph->mutex_l_fork);
// 			pthread_mutex_unlock(ph->mutex_r_fork);
// 			if ( ph->isforkfree == false && ph->next->isforkfree == false)
// 				ph->state = EATING;
// 			//pthread_mutex_lock(&ph->philo->mutex_print);
// 			printf("Philo %d is %s... and asking for forks R-fork is:%d L-fork is: %d \n", ph->id, char_state(ph->state), (int)ph->isforkfree, (int)ph->next->isforkfree);
// 			//pthread_mutex_unlock(&ph->philo->mutex_print);
// 		}
// 		// EATING TIME
// 		// if (ph->state == EATING)
// 		// {
// 		// 	//WAIT TIME FOR EATING.
// 		// 	sleep(1);
// 		// 	// WAIT TIME TO SLEEP.
// 		// 	sleep(1);
// 		// 	ph->state = THINKING;
// 		// 	pthread_mutex_lock(ph->mutex_r_fork);
// 		// 	pthread_mutex_unlock(&ph->mutex_l_fork);
// 		// 		ph->isforkfree = true;
// 		// 		ph->next->isforkfree = true;
// 		// 	pthread_mutex_unlock(&ph->mutex_l_fork);
// 		// 	pthread_mutex_unlock(ph->mutex_r_fork);
// 		// 	pthread_mutex_lock(&ph->philo->mutex_print);
// 		// 	printf("Philo %d is %s... R-fork is:%d L-fork is: %d \n", ph->id, char_state(ph->state), (int)ph->isforkfree, (int)ph->next->isforkfree);
// 		// 	pthread_mutex_unlock(&ph->philo->mutex_print);
// 		//}
// 	}
// 	return NULL;
// }

void philo_take_forks(t_philosopher *ph)
{
	pthread_mutex_lock(&ph->mutex_l_fork);
	pthread_mutex_lock(ph->mutex_r_fork);
	ph->isforkfree = false;
	ph->next->isforkfree = false;
	pthread_mutex_unlock(&ph->mutex_l_fork);
	pthread_mutex_unlock(ph->mutex_r_fork);
}


void philo_eat(t_philosopher *ph)
{
	philo_take_forks(ph);
	printf("Philo %d is %s... and asking for forks R-fork is:%d L-fork is: %d \n", ph->id, char_state(ph->state), (int)ph->isforkfree, (int)ph->next->isforkfree);
}

/* Routine for infinitive loop */
void *routine(void *arg)
{
	t_philosopher *ph;

	ph = (t_philosopher *)arg;
	while (1)
	{
		/* code */
		philo_eat(ph);
	}
}

int philo_create(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphs)
	{
		pthread_create(&philo->phs[i].thr_ph, NULL, routine, &philo->phs[i]);
		i++;
	}
	return (EXIT_FAILURE);
}