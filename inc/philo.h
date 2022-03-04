/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:05:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/04 16:51:54 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************* */
/* STD LIBC INCLUDES														 */
/* ************************************************************************* */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

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
	DEAD,
	NOSTATUS,
} t_status;


// usr/include/stdlib.h:394,
// struct timeval {
// 	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
// 	suseconds_t  tv_usec;  /* and microseconds */
// };

// struct timezone {
// 	int     tz_minuteswest; /* of Greenwich */
// 	int     tz_dsttime;     /* type of dst correction to apply */
// };



typedef struct s_philosopher
{
	pthread_t				thr_ph;
	int						id;				/* Starting in 1. (index + 1) */
	t_status				state;
	pthread_mutex_t 		mutex_l_fork;		/* Same as the philosopher */
	bool					isforkfree;
	pthread_mutex_t 		*mutex_r_fork;		/* maybe. Next philosopher fork */
	int						ts_take_fork;
	int						ts_eating;
	int						ts_sleeping;
	int						ts_thinking;
	int						ts_died;
	struct s_philosopher	*next;
	struct s_philo			*philo;			/* pointer to t_philo */
}	t_philosopher;

/***
 * Main struct.
 * 
***/
typedef struct s_philo
{
	int				nphs;			/* number_of_philosophers */
	t_philosopher	*phs;			/* array of t_philos*/
	int				time2die;		/* time_to_die (in milliseconds) */
	int				time2eat;		/* time_to_eat (in milliseconds) */
	int				time2sleep;		/* time_to_sleep (in milliseconds) */
	int				ntimes2eat;		/* number_of_times_each_philosopher_must_eat (optional argument */
	pthread_mutex_t	mutex_print;
}	t_philo;


/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

/*
 * PHILOSOPHERS
 */
int		philo_parser_arg(int args, char **argv, t_philo *philo);
int		philo_init(t_philo *philo);
int		philo_mutex(t_philo *philo);
int		philo_create(t_philo *philo);
int		philo_join(t_philo *philo);


/*
 * ROUTINES
 */
void *routine(void *arg);

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
int 	print_mtime(void);
long    print_milis(void);

/*
 * ERROR
 */
int error_msg(char *msg);

#endif