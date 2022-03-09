/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:21:50 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:57:09 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dinner_init(t_philo *dinner)
{
	dinner->infinity = false;
	dinner->nphs = 0;
	dinner->ntimes2eat = 0;
	dinner->time2die = 0;
	dinner->time2eat = 0;
	dinner->time2sleep = 0;
	dinner->running = true;
}

int	main(int args, char **argv)
{
	t_philo	philo;

	dinner_init(&philo);
	if (philo_parser_arg(args, argv, &philo))
		return (EXIT_FAILURE);
	if (philo_init(&philo))
		return (EXIT_FAILURE);
	if (philo_mutex(&philo))
		return (EXIT_FAILURE);
	if (philo_create(&philo))
		return (EXIT_FAILURE);
	if (philo_join(&philo))
		return (EXIT_FAILURE);
	free_mem(&philo);
	return (EXIT_SUCCESS);
}
