/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:03:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/03 16:32:47 by amorcill         ###   ########.fr       */
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

void *routine_eat(void *arg)
{
	// int i;
	// int nphs;
	t_philosopher *ph;
	
	ph = (t_philosopher *)arg;	
	// t_philosopher *next_ph;
	// i = ph->id - 1;
	// nphs = ((t_philo *)ph->philo)->nphs;
	// next_ph = &((t_philo *)ph->philo)->phs[((i + 1) % nphs)];

	pthread_mutex_lock(&ph->mutex_l_fork);
	pthread_mutex_lock(ph->mutex_r_fork);
	//if (ph->isforkfree == true && next_ph->isforkfree == true)
	if (ph->isforkfree == true && ph->next->isforkfree == true)
	{
		ph->isforkfree = false;
		ph->next->isforkfree = false;
		ph->state = EATING;
	}
	pthread_mutex_unlock(&ph->mutex_l_fork);
	pthread_mutex_unlock(ph->mutex_r_fork);
	printf("Philo %d is %s\n", ph->id, char_state(ph->state));
	return NULL;
}

int philo_create(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphs)
	{
		pthread_create(&philo->phs[i].thr_ph, NULL, routine_eat, &philo->phs[i]);
		i++;
	}
	return (EXIT_FAILURE);
}