/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:53 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/10 21:09:37 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philosopher_new(int i, t_philosopher *ph, t_philo *philo)
{
	ph->id = i + 1;
	if ((i % 2) == 0)
		ph->state = THINKING;
	else
		ph->state = SLEEPING;
	ph->hasfork = false;
	ph->philo = philo;
	ph->ntimes2eat = philo->ntimes2eat;
	ph->next = NULL;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
}

int	philo_init(t_philo *philo)
{
	int	i;

	philo->phs = (t_philosopher *)malloc(sizeof(t_philosopher) * philo->nphs);
	if (philo->phs == NULL)
		return (error_msg("Error: malloc not correct\n"));
	i = 0;
	while (i < philo->nphs)
	{	
		philo->phs[i].thr = (pthread_t *)malloc(sizeof(pthread_t));
		if (philo->phs[i].thr == NULL)
			return (error_msg("Error: Failed to allocate mem for thread"));
		philosopher_new(i, &philo->phs[i], philo);
		i++;
	}
	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].next = &philo->phs[((i + 1) % philo->nphs)];
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

static int	philo_semaphore2(t_philo *philo)
{
	int	i;

	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].sem_r_fork
				= philo->phs[((i + 1) % philo->nphs)].sem_l_fork;
			i++;
		}
	}
	philo->sem_print = sem_open("sem_print", O_CREAT, 0644, 2);
	if (philo->sem_print == SEM_FAILED)
		return (error_msg("Error: Failed to initialize semaphore\n"));
	philo->sem_running = sem_open("sem_running", O_CREAT, 0644, 2);
	if (philo->sem_running == SEM_FAILED)
		return (error_msg("Error: Failed to initialize semaphore\n"));
	return (EXIT_SUCCESS);
}

int	philo_semaphore(t_philo *philo)
{
	int		i;
	char	*tmp_n;
	char	*sem_name;

	i = 0;
	while (i < philo->nphs)
	{
		tmp_n = ft_itoa(i);
		sem_name = ft_strjoin("sem_l_fork", tmp_n);
		if (tmp_n)
			free(tmp_n);
		philo->phs[i].sem_l_fork = sem_open(sem_name, O_CREAT, 0666, 2);
		if (philo->phs[i].sem_l_fork == SEM_FAILED)
			return (error_msg("Error: Failed to initialize semaphore\n"));
		if (sem_name)
			free(sem_name);
		i++;
	}
	if (philo_semaphore2(philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
