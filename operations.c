/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:26:58 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 15:44:17 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	take_forks(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&philo->left->mutex);
	pthread_mutex_lock(&philo->right->mutex);
	log_printer_single(rules, "has taken a fork", philo);
	log_printer_single(rules, "has taken a fork", philo);
}

void	leave_forks(t_philo *philo, t_rules *rules)
{
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
	log_printer_single(rules, "is sleeping", philo);
	ft_usleep(rules->time_sleep);
	log_printer_single(rules, "is thinking", philo);
}

void	eat(t_rules *rules, t_philo *philo)
{
	int	difference;

	take_forks(philo, rules);
	difference = get_time() - philo->info->sim_start;
	if ((difference - philo->last_meal) >= philo->info->time_death)
	{
		log_printer_single(philo->info, "died", philo);
		philo->info->some_died = 1;
		return ;
	}
	log_printer_single(rules, "is eating", philo);
	philo->last_meal = get_time() - rules->sim_start;
	philo->eaten_ntimes++;
	if (philo->eaten_ntimes == rules->num_times_eat)
		rules->all_eaten++;
	ft_usleep(rules->time_eat);
	leave_forks(philo, rules);
}

bool	philo_status(t_philo *philo)
{
	int	difference;

	difference = get_time() - philo->info->sim_start;
	pthread_mutex_lock(&philo->info->is_printing);
	pthread_mutex_unlock(&philo->info->is_printing);
	if ((difference - philo->last_meal) >= philo->info->time_death)
	{
		log_printer_single(philo->info, "died", philo);
		philo->info->some_died = 1;
		return (false);
	}
	if (philo->info->all_eaten == philo->info->philo_num)
		return (false);
	return (true);
}

void	start_routine(t_philo *philo)
{
	while (philo_status(philo))
		eat(philo->info, philo);
	return ;
}
