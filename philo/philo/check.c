/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:59 by esanli            #+#    #+#             */
/*   Updated: 2023/03/09 17:44:14 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_check(t_phil *ph)
{
	if (ph->max_eat != 0)
	{
		if (ph->nbr_eat == ph->max_eat)
			return (0);
	}
	return (1);
}

void	philo_died(t_phil *ph)
{
	pthread_mutex_lock(ph->lock);
	if (!(*(ph->stop_prog)))
	{
		printf("%-5ld %d died\n", ph->now_time, ph->phil_id);
		*ph->stop_prog = 1;
	}
	pthread_mutex_unlock(ph->lock);
}

void	death_check(t_phil *ph)
{
	while (42)
	{
		pthread_mutex_lock(ph->lock);
		if (*ph->stop_prog)
			return ;
		pthread_mutex_unlock(ph->lock);
		usleep(20);
	}
}
