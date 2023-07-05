/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:54 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 15:54:08 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdarg.h>
# include <stdbool.h>

# define NC "\e[0m"
# define G "\e[1;32m"
# define R "\e[1;31m"
# define C "\e[1;36m"
# define Y "\e[1;33m"
# define M "\e[1;35m"
# define W "\e[1;37m"

//------------rules structure
typedef struct rules
{
	int				philo_num;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				num_times_eat;
	int				sim_start;
	int				some_died;
	int				all_eaten;
	pthread_mutex_t	is_printing;
}		t_rules;

//------------fork structure
typedef struct fork
{
	int				id;
	pthread_mutex_t	mutex;
}		t_fork;

//------------philo structure
typedef struct philo
{
	int			id;
	t_fork		*left;
	t_fork		*right;
	int			eaten_ntimes;
	int			last_meal;
	t_rules		*info;
}		t_philo;

//------------initializers.c
void		*init_func(void *arg);
int			init_rules(char **argv, int argc, t_rules *rules);
int			init_philos(t_rules *rules, t_philo *philos, t_fork *forks);
void		init_forks(int num, t_fork *forks);

//------------checkers.c
int			check_params(char **argv, int argc);
int			is_int(char *str);
int			is_num(char *str);

//------------utils.c
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
int			ft_strcmp(char *strg1, char *strg2);
int			get_time(void);
void		ft_usleep(int ms);

//------------printers.c
void		log_printer(t_rules *rules, t_philo *philos);
void		log_printer_single(t_rules *rules, char *str, t_philo *philo);
int			print_errors(char *str, t_rules *rules);

//------------operations.c
void		take_forks(t_philo *philo, t_rules *rules);
void		leave_forks(t_philo *philo, t_rules *rules);
void		eat(t_rules *rules, t_philo *philo);
bool		philo_status(t_philo *philo);
void		start_routine(t_philo *philo);

//----------------ft_printf.c & co
int			ft_get_type(char c, va_list args);
int			ft_printf(const char *s, ...);
int			ft_printer(char c);
int			lenght(int nb, int base);
char		*ft_itoa(int nb);
int			ft_putnbr(int n);
int			ft_ptr_len(uintptr_t n);
void		ft_print_ptr(uintptr_t n);
int			ft_putptr(unsigned long long n);
int			ft_putunsigned(unsigned int nb);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_hex_len(unsigned int n);
void		ft_print_hex(unsigned int n, char letter);
int			ft_puthex(unsigned int n, char letter);

//----------------small_philos.c
int			one_philo(t_rules *rules, t_philo *philos, t_fork *forks);

#endif
