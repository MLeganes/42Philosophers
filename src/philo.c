/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:21:50 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 21:09:38 by amorcill         ###   ########.fr       */
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

int	philo_parser_arg(int args, char **argv, t_philo *philo)
{
	if (args < 5)
		return (error_parser_msg("Error: missing arguments\n"));
	if (args > 6)
		return (error_parser_msg("Error: too many arguments\n"));
	if (ft_atoi_ext(argv[1], &philo->nphs) == 0)
		return (error_parser_msg("Error: arguments are not correct\n"));
	if (philo->nphs <= 0)
		return (error_parser_msg("Error: at least one philosopher required\n"));
	if (ft_atoi_ext(argv[2], &philo->time2die) == 0
		|| ft_atoi_ext(argv[3], &philo->time2eat) == 0
		|| ft_atoi_ext(argv[4], &philo->time2sleep) == 0)
		return (error_parser_msg("Error: arguments are not correct\n"));
	if (args == 6)
	{
		if (ft_atoi_ext(argv[5], &philo->ntimes2eat) == 0)
			return (error_parser_msg("Error: arguments are not correct\n"));
	}
	else
		philo->infinity = true;
	return (EXIT_SUCCESS);
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
