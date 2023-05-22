/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:32 by esanli            #+#    #+#             */
/*   Updated: 2023/03/10 13:31:01 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*only_one(t_phil *ph)
{
	printf("%-5ld %d has taken a fork\n", \
	ph->now_time, ph->phil_id);
	usleep(ph->die_time * 1000);
	printf("%-5ld %d died\n", ph->die_time, ph->phil_id);
	pthread_mutex_lock(ph->lock);
	*ph->stop_prog = 1;
	pthread_mutex_unlock(ph->lock);
	return (NULL);
}

void	*begin(void *data)
{
	t_phil	*ph;

	ph = (t_phil *)data;
	if (ph->phil_nbr == 1)
		return (only_one(ph));
	if (ph->phil_id % 2 == 0)
		usleep(100);
	eat_time(ph);
	pthread_mutex_lock(ph->lock);
	(*ph->philo_ate)++;
	if (*ph->philo_ate == ph->phil_nbr)
		*(ph->stop_prog) = 1;
	pthread_mutex_unlock(ph->lock);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_phil	*ph;
	int		i;

	if (ac != 5 && ac != 6)
		return (error(ARG_COUNT));
	if (!check_args(av))
		return (error(ARG_CONTROL));
	ph = (t_phil *)malloc(sizeof(t_phil) * ft_atoi(av[1]));
	ft_mutex_fork(ph, av);
	set_value(ph, av);
	i = 0;
	while (i < ph->phil_nbr)
	{
		pthread_create(&ph[i].thread_id, NULL, begin, &ph[i]);
		pthread_detach(ph[i].thread_id);
		i++;
	}
	death_check(ph);
	ft_free(ph);
	return (0);
}
