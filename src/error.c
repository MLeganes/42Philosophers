/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:29:03 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/06 02:07:08 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

static void print_instruction(void)
{
	ft_putstr_fd(REDD, 1);

	ft_putstr_fd("\n""Arguments \n", 1);
	ft_putstr_fd(REDD"[ number_of_philosophers ]"RESET"\n", 1);
	ft_putstr_fd(REDD"[ time_to_die ]"RESET"-> milliseconds\n", 1);
	ft_putstr_fd(REDD"[ time_to_eat ]"RESET"-> milliseconds\n", 1);
	ft_putstr_fd(REDD"[ time_to_sleep ]"RESET"-> milliseconds\n", 1);
	ft_putstr_fd(REDD"[ number_of_times_each_philosopher_must_eat ]"RESET"-> optional\n", 1);
	ft_putstr_fd("\n""Example: ./philo 2 120 60 60 2", 1);
	ft_putstr_fd("\n""Example: ./philo 2 800 600 300", 1);
	ft_putstr_fd("\n""Example: ./philo 4 400 200 200\n", 1);
}

int	error_msg(char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	print_instruction(); //Change this only to print in parser.
	return (EXIT_FAILURE);
}

