/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:38:53 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 15:50:35 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	is_num(char *str)
{
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	is_int(char *str)
{
	int	temp;

	if (strlen(str) > 11)
		return (0);
	temp = ft_atoi(str);
	if (temp == -1 && ft_strlen(str) > 2)
		return (0);
	return (1);
}

int	is_not_zero(char *str)
{
	int	temp;

	temp = ft_atoi(str);
	if (temp == 0)
		return (0);
	return (1);
}

int	check_params(char **argv, int argc)
{
	if (argc <= 4 || argc >= 7)
	{
		ft_printf("Error\n");
		return (1);
	}
	argv++;
	while (*argv)
	{
		if (is_num(*argv) && is_int(*argv) && is_not_zero(*argv))
			argv++;
		else
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	return (0);
}
