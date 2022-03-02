/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:05:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/02 12:16:29 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

# define MAGENTA "\e[35m"
# define BLUE  "\e[32m"
# define LIGHTYELLOW "\e[93m"
# define REDD  "\e[92m"
# define RESET  "\e[0m"

# define ERROR		-1
# define SUCCESS	0
# define READ		0
# define WRITE		1
# define INFINITY	-10


/* ************************************************************************** */
/* STRUCT DEFS															  	  */
/* ************************************************************************** */

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	NOSTATUS,
} t_status;


// usr/include/stdlib.h:394,
// struct timeval {
// 	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
// 	suseconds_t  tv_usec;  /* and microseconds */
// };

struct timezone {
	int     tz_minuteswest; /* of Greenwich */
	int     tz_dsttime;     /* type of dst correction to apply */
};




typedef struct s_philosopher
{
	int				id; //Starting in 1. (index + 1)
	pthread_t		thr_ph;
	t_status		state;
	pthread_mutex_t left_fork;
	pthread_mutex_t *right_fork; //maybe
	int				ts_take_fork;
	int				ts_eating;
	int				ts_sleeping;
	int				ts_thinking;
	int				ts_died;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				ntimes2eat;
	
}	t_philosopher;

/***
 * 
 * 
***/
typedef struct s_philo
{
	int				nphs;	/* number_of_philosophers */
	t_philosopher	*phs;	/* array of t_philos*/
	int				time2die;		/* time_to_die (in milliseconds) */
	int				time2eat;		/* time_to_eat (in milliseconds) */
	int				time2sleep;		/* time_to_sleep (in milliseconds) */
	int				ntimes2eat;		/* number_of_times_each_philosopher_must_eat (optional argument */
	
}	t_philo;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

/*
 * PHILOSOPHERS
 */
int		philo_parser_arg(int args, char **argv, t_philo *philo);
int		philo_create(t_philo *philo);
int		philo_join(t_philo *philo);
/*
 * FREE
 */
void	free_mem();

/*
 * UTILS
 */
size_t	ft_strlen(const char *ch);
int		ft_isdigit(int c);
int		ft_atoi_ext(const char *str, int *nbr);

/*
 * ERROR
 */
int error_msg(char *msg);

#endif