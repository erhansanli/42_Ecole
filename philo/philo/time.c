/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:25 by esanli            #+#    #+#             */
/*   Updated: 2023/03/10 13:43:35 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time(t_phil *ph)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	ph->time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (ph->start_time == 0)
		ph->start_time = ph->time_ms;
	ph->now_time = ph->time_ms - ph->start_time;
}

int	my_sleep(t_phil *ph, size_t time)
{
	unsigned long int	c_time;

	get_time(ph);
	c_time = ph->now_time;
	while (ph->now_time < c_time + time)
	{
		get_time(ph);
		if (ph->now_time > ph->last_eat)
		{
			philo_died(ph);
			return (1);
		}
		usleep(time);
	}
	return (0);
}

void	think_time(t_phil *ph)
{
	get_time(ph);
	pthread_mutex_lock(ph->lock);
	if (*ph->stop_prog != 1)
		printf("%-5ld %d is thinking\n", ph->now_time, ph->phil_id);
	pthread_mutex_unlock(ph->lock);
	eat_time(ph);
}

void	sleep_time(t_phil *ph)
{
	get_time(ph);
	pthread_mutex_lock(ph->lock);
	if (*ph->stop_prog != 1)
		printf("%-5ld %d is sleeping\n", ph->now_time, ph->phil_id);
	pthread_mutex_unlock(ph->lock);
	my_sleep(ph, ph->sleep_time);
	think_time(ph);
}

void	*eat_time(t_phil *ph)
{
	if (eat_check(ph))
	{
		get_time(ph);
		pthread_mutex_lock(ph->right_fork);
		pthread_mutex_lock(ph->left_fork);
		get_time(ph);
		pthread_mutex_lock(ph->lock);
		if (*ph->stop_prog != 1)
		{
			printf("%-5ld %d has taken a fork\
			\n%-5ld %d has taken a fork\n%-5ld %d is eating\n", \
			ph->now_time, ph->phil_id, \
			ph->now_time, ph->phil_id, \
			ph->now_time, ph->phil_id);
		}
		pthread_mutex_unlock(ph->lock);
		my_sleep(ph, ph->eat_time);
		ph->nbr_eat++;
		ph->last_eat = ph->now_time + ph->die_time;
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		sleep_time(ph);
	}
	return (NULL);
}
