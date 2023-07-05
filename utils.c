/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:41:53 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 15:52:21 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	value;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	value *= sign;
	if (value < -2147483648 || value > 2147483647)
		return (-1);
	return ((int)value);
}

int	ft_strcmp(char *strg1, char *strg2)
{
	while ((*strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2)
	{
		strg1++;
		strg2++;
	}
	if (*strg1 == *strg2)
		return (0);
	else
		return (*strg1 - *strg2);
}

int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	int	end;

	end = get_time() + ms;
	while (get_time() < end)
		usleep(ms / 1000);
}
