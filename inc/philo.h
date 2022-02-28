/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:05:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/02/28 16:15:45 by amorcill         ###   ########.fr       */
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
# include <pthread.h>

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

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DIED,
} t_status;


struct timeval {
	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
	suseconds_t  tv_usec;  /* and microseconds */
};

struct timezone {
	int     tz_minuteswest; /* of Greenwich */
	int     tz_dsttime;     /* type of dst correction to apply */
};




typedef struct s_philosopher
{
	pthread_t	pth_ph;
	t_status	state;
	int			ranking_n; //Starting in 1. (index + 1)
	int			ts_takee_fork;
	int			ts_eating;
	int			ts_sleeping;
	int			ts_thinking;
	int			ts_died;
	
}	t_philosopher;

/***
 * 
 * 
***/
typedef struct s_philo
{
	int				nphilosophers;
	t_philosopher	*philosophers;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				ntimes_must_eat;
	
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
