/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:39:50 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:34:32 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
