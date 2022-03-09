/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:29:03 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 19:22:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

static void	print_instruction(void)
{
	ft_putstr_fd(REDD, 1);
	ft_putstr_fd("\n""Arguments \n", 1);
	ft_putstr_fd(REDD"[ number_of_philosophers ]"RESET"\n", 1);
	ft_putstr_fd(REDD"[ time_to_die ]"RESET"-> ms\n", 1);
	ft_putstr_fd(REDD"[ time_to_eat ]"RESET"-> ms\n", 1);
	ft_putstr_fd(REDD"[ time_to_sleep ]"RESET"-> ms\n", 1);
	ft_putstr_fd(
		REDD"[ number_of_times_each_philosopher_must_eat ]"RESET"-> opt\n", 1);
	ft_putstr_fd("\n""Example: ./philo 2 120 20 20 2", 1);
	ft_putstr_fd("\n""Example: ./philo 2 800 200 300", 1);
	ft_putstr_fd("\n""Example: ./philo 4 400 200 200\n", 1);
}

int	error_parser_msg(char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	print_instruction();
	return (EXIT_FAILURE);
}

int	error_msg(char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}
