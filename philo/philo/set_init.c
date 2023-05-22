/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:52 by esanli            #+#    #+#             */
/*   Updated: 2023/03/10 13:28:37 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_fork(t_phil *ph, char **av)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < ft_atoi(av[1]))
		pthread_mutex_init(&forks[i++], NULL);
	ph->fork = forks;
}

void	set_value2(t_phil *ph, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ph[i].phil_nbr = (size_t)ft_atoi(av[1]);
		ph[i].die_time = (size_t)ft_atoi(av[2]);
		ph[i].eat_time = (size_t)ft_atoi(av[3]);
		ph[i].sleep_time = (size_t)ft_atoi(av[4]);
		ph[i].last_eat = (size_t)ft_atoi(av[2]);
		ph[i].nbr_eat = 0;
		ph[i].max_eat = 0;
		if (av[5])
			ph[i].max_eat = ft_atoi(av[5]);
		i++;
	}
	ph->start_time = 0;
	ph->now_time = 0;
	ph->time_ms = 0;
}

void	set_value(t_phil *ph, char **av)
{
	int					i;
	int					*k;
	int					*j;
	pthread_mutex_t		*locked;

	k = malloc(sizeof(int));
	*k = 0;
	j = malloc(sizeof(int));
	*j = 0;
	locked = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(locked, NULL);
	set_value2(ph, av);
	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		ph[i].phil_id = i + 1;
		ph[i].right_fork = &ph->fork[i];
		ph[i].left_fork = &ph->fork[i + 1];
		ph[i].lock = locked;
		ph[i].stop_prog = k;
		ph[i].philo_ate = j;
	}
	ph[i - 1].left_fork = &ph->fork[0];
}
