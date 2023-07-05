/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:39:16 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 14:00:24 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	*init_func(void *vp)
{
	t_philo		*philo;

	philo = (t_philo *)vp;
	start_routine(philo);
	return ((void *)0);
}

int	init_rules(char **argv, int argc, t_rules *rules)
{
	if (ft_atoi(argv[1]) > 200)
	{
		ft_printf("Max 200 philosophers allowed!\n");
		return (1);
	}
	rules->philo_num = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->num_times_eat = ft_atoi(argv[5]);
	else
		rules->num_times_eat = 2147483647;
	rules->some_died = 0;
	rules->all_eaten = 0;
	pthread_mutex_init(&rules->is_printing, NULL);
	return (0);
}

int	init_philos(t_rules *rules, t_philo *philos, t_fork *forks)
{
	int			i;
	pthread_t	*ntid;

	ntid = malloc(sizeof(pthread_t) * rules->philo_num);
	i = -1;
	if (rules->philo_num == 1)
		return (print_errors("onephilo", rules));
	while (++i < rules->philo_num)
	{
		philos[i].id = i + 1;
		philos[i].eaten_ntimes = 0;
		philos[i].left = &forks[i];
		philos[i].right = &forks[(i + 1) % rules->philo_num];
		philos[i].info = rules;
		philos[i].last_meal = 0;
		rules->sim_start = get_time();
		if (pthread_create(&ntid[i], NULL, &init_func, &philos[i]))
			return (print_errors("create", rules));
	}
	while (rules->some_died != 1 && (rules->all_eaten != rules->philo_num))
		ft_usleep(1);
	free(ntid);
	return (0);
}

void	init_forks(int num, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < num)
	{
		forks[i].id = i + 1;
		pthread_mutex_init(&forks[i].mutex, NULL);
		i++;
	}
}
