/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:30:59 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/09 20:14:17 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *ch)
{
	int	count;

	count = 0;
	if (ch == NULL)
		return (0);
	while (*(ch + count))
	{
		count++;
	}
	return (count);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n'
			|| c == ' '))
		return (1);
	return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

/**
 * @brief	The ft_strtoi() function converts the string in str to a int value.
 * 			The string may begin with an arbitrary amount of white space (as 
 * 			determined by ft_isspace) followed by a single optional `+' or `-' 
 * 			sign. Base is taken as 10 (decimal) by default.
 * 
 * @param str The sting with the number.
 * @param nbr Pointer to return the integer number.
 * @return int The ft_strtoi() function return the result of the conversion:
 * 	1 the conversion was successful.
 * 	0 is returned, if no conversion could be performed.
 */
int	ft_atoi_ext(const char *str, int *nbr)
{
	unsigned int	ret;
	int				sign;
	int				i;

	sign = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = ft_sign(str[i]);
		i++;
	}
	while (str[i] != '\0' && ret <= 2147483648)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if ((sign == -1 && ret > 2147483648) || (sign == 1 && ret > 2147483647))
		return (0);
	*nbr = (int)(sign * ret);
	return (1);
}
