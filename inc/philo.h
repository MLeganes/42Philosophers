/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:05:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 22:06:22 by amorcill         ###   ########.fr       */
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
# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"
# define MAGENTA "\e[35m"
# define BLUEE  "\e[32m"
# define REDD  "\e[92m"
# define RESET  "\e[0m"

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
}	t_status;

typedef struct s_philosopher
{
	int						id;
	t_status				state;
	pthread_t				*thr;
	pthread_mutex_t			mutex_l_fork;
	bool					hasfork;
	pthread_mutex_t			*mutex_r_fork;
	const struct timeval	start_eating;
	int 					ntimes2eat;
	struct s_philosopher	*next;
	struct s_philo			*philo;
}	t_philosopher;

/***
 * Main struct.
 * 
***/
typedef struct s_philo
{
	bool					running;
	pthread_mutex_t			mutex_running;
	int						nphs;
	t_philosopher			*phs;
	int						time2die;
	int						time2eat;
	int						time2sleep;
	int						ntimes2eat;
	bool					infinity;
	const struct timeval	start_dinner;
	pthread_mutex_t			mutex_print;
}	t_philo;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

/*
 * PHILOSOPHERS
 */
int			philo_parser_arg(int args, char **argv, t_philo *philo);
int			philo_init(t_philo *philo);
int			philo_mutex(t_philo *philo);
int			philo_create(t_philo *philo);
void		philo_eat(t_philosopher *ph);
int			philo_join(t_philo *philo);

/*
 * TIME
 */
bool		print_time_msg(t_philosopher *philo, char *msg);
int			gettimediff(struct timeval *t);
long		gettime(void);
t_status	time_countdown(t_philosopher *ph, int countdown);

/*
 * UTILS
 */
size_t		ft_strlen(const char *ch);
int			ft_isdigit(int c);
int			ft_atoi_ext(const char *str, int *nbr);

/*
 * FREE
 */
void		free_mem(t_philo *ph);

/*
 * ERROR
 */
int			error_msg(char *msg);
int			error_parser_msg(char *msg);

#endif