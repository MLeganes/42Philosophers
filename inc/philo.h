/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:05:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/02/25 12:32:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/***************************************************************************/
/* STD LIBC INCLUDES													   */
/***************************************************************************/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* ************************************************************************** */
/* COLORS																	..*/
/* ************************************************************************** */
# define GREEN		"\033[32m"
# define RED		"\033[35m"
# define RE			"\033[0m"

# define ERROR		-1
# define SUCCESS	0
# define READ		0
# define WRITE		1

/* ************************************************************************** */
/* STRUCT DEFS															  	  */
/* ************************************************************************** */

/***
 * 
 * 
***/
typedef struct s_philo
{
	
}	t_philo;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

/*
 * PHILOSOPHERS
 */
int main(int args, char **argv);
void	free_mem();

#endif