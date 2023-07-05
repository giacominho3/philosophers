/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:50:58 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/08 15:00:44 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	*philos;
	t_fork	*forks;
	int		i;

	if (check_params(argv, argc))
		return (1);
	rules = malloc(sizeof(t_rules));
	if (init_rules(argv, argc, rules))
		return (1);
	philos = malloc(sizeof(t_philo) * rules->philo_num);
	forks = malloc(sizeof(t_fork) * rules->philo_num);
	init_forks(rules->philo_num, forks);
	if (init_philos(rules, philos, forks))
		return (1);
	i = -1;
	while (++i < rules->philo_num)
		pthread_mutex_destroy(&forks[i].mutex);
	free(philos);
	free(forks);
	free(rules);
	return (0);
}
