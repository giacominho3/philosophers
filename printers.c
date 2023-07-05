/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:07:58 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 12:01:37 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	log_printer_single(t_rules *rules, char *str, t_philo *philo)
{
	unsigned long int	time;

	time = get_time() - rules->sim_start;
	if (rules->time_eat < 100 || rules->time_sleep < 100)
	{
		while (time % 60 != 0)
			time--;
	}
	else
	{
		while (time % 100 != 0)
			time--;
	}
	if (rules->some_died || (rules->philo_num == rules->all_eaten))
		return ;
	pthread_mutex_lock(&rules->is_printing);
	if (!ft_strcmp(str, "died"))
	{
		ft_printf("%u %d died\n", time, philo->id);
		return ;
	}
	ft_printf("%u %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&rules->is_printing);
}

int	print_errors(char *str, t_rules *rules)
{
	pthread_mutex_lock(&rules->is_printing);
	if (!ft_strcmp(str, "create"))
		ft_printf("Error creating thread!\n");
	if (!ft_strcmp(str, "join"))
		ft_printf("Error joining thread!\n");
	if (!ft_strcmp(str, "onephilo"))
	{
		ft_printf("0 1 has taken a fork\n");
		ft_usleep(rules->time_death);
		ft_printf("%d 1 died\n", rules->time_death);
	}
	pthread_mutex_unlock(&rules->is_printing);
	return (1);
}
