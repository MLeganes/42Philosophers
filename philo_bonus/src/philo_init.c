/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:53 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/10 20:00:48 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = '\0';
		count++;
	}
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		count;
	char	*ret;

	count = 0;
	len = ft_strlen(s);
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		while (count < len)
		{
			ret[count] = s[count];
			count++;
		}
		ret[count] = '\0';
	}
	return (ret);
}


static int	ft_intlen(int n)
{
	int		count;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = 0;
		n = n * -1;
	}
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (sign == 0)
		count++;
	return (count);
}

static char	*ft_inttostr(int sign, int n, char *ret)
{
	while (n != 0)
	{
		*ret = (n % 10) + '0';
		ret--;
		n = n / 10;
	}
	ret++;
	if (sign == 0)
	{
		ret--;
		*ret = '-';
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		nlen;

	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	nlen = ft_intlen(n);
	ret = (char *)malloc((char)nlen + 1);
	if (ret == 0)
		return (0);
	ft_bzero(ret, nlen + 1);
	ret = ret + nlen - 1;
	if (n < 0)
	{
		n = n * (-1);
		ret = ft_inttostr(0, n, ret);
	}
	else
		ret = ft_inttostr(1, n, ret);
	return (ret);
}


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	size_t	i;
	char	*strjoin;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = malloc(len1 + len2 + 1);
	if (!strjoin)
		return (0);
	index = 0;
	while (s1 != NULL && s1[index] != '\0')
	{
		strjoin[index] = s1[index];
		index++;
	}
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		strjoin[index++] = s2[i++];
	strjoin[index] = '\0';
	return (strjoin);
}



static void	philosopher_new(int i, t_philosopher *ph, t_philo *philo)
{
	ph->id = i + 1;
	if ((i % 2) == 0)
		ph->state = THINKING;
	else
		ph->state = SLEEPING;
	ph->hasfork = false;
	ph->philo = philo;
	ph->ntimes2eat = philo->ntimes2eat;
	ph->next = NULL;
	gettimeofday((struct timeval *)&ph->start_eating, NULL);
}

int	philo_init(t_philo *philo)
{
	int	i;

	philo->phs = (t_philosopher *)malloc(sizeof(t_philosopher) * philo->nphs);
	if (philo->phs == NULL)
		return (error_msg("Error: malloc not correct\n"));
	i = 0;
	while (i < philo->nphs)
	{	
		philo->phs[i].thr = (pthread_t *)malloc(sizeof(pthread_t));
		if (philo->phs[i].thr == NULL)
			return (error_msg("Error: Failed to allocate mem for thread"));
		philosopher_new(i, &philo->phs[i], philo);
		i++;
	}
	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].next = &philo->phs[((i + 1) % philo->nphs)];
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int	philo_mutex(t_philo *philo)
{
	int	i;
	char		*sem_name;
	char		*tmp_n;

	i = 0;
	while (i < philo->nphs)
	{
		tmp_n = ft_itoa(i);
		sem_name = ft_strjoin("sem_l_fork", tmp_n);
		if (tmp_n)
			free(tmp_n);

		if ( (philo->phs[i].sem_l_fork = sem_open(sem_name, O_CREAT, 0666, 2)) == SEM_FAILED)
			return (error_msg("Error: Failed to initialize semaphore\n"));
				
		// if (pthread_mutex_init(&philo->phs[i].mutex_l_fork, NULL) != 0)
		// 	return (error_msg("Error: Failed to initialize mutex\n"));
		if(sem_name)
			free(sem_name);
		i++;
	}
	if (philo->nphs > 1)
	{
		i = 0;
		while (i < philo->nphs)
		{
			philo->phs[i].sem_r_fork = philo->phs[((i + 1) % philo->nphs)].sem_l_fork;
			i++;
		}
	}
	// if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
	// 	return (error_msg("Error: Failed to initialize mutex\n"));
	// if (pthread_mutex_init(&philo->mutex_running, NULL) != 0)
	// 	return (error_msg("Error: Failed to initialize mutex\n"));
	
	philo->sem_print = sem_open("sem_print", O_CREAT, 0644, 2);
	if (philo->sem_print == SEM_FAILED)
		return (error_msg("Error: Failed to initialize semaphore\n"));
	philo->sem_running = sem_open("sem_running", O_CREAT, 0644, 2);
	if (philo->sem_running == SEM_FAILED)
		return (error_msg("Error: Failed to initialize semaphore\n"));
	return (EXIT_SUCCESS);
}