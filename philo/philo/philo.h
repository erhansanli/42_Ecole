/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:49:57 by esanli            #+#    #+#             */
/*   Updated: 2023/03/10 13:43:49 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARG_COUNT 1
# define ARG_CONTROL 2

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_phil
{
	int						phil_id;
	int						phil_nbr;
	size_t					die_time;
	size_t					eat_time;
	size_t					sleep_time;
	int						max_eat;
	int						nbr_eat;
	int						*stop_prog;
	int						*philo_ate;
	size_t					now_time;
	size_t					last_eat;
	size_t					time_ms;
	size_t					start_time;
	pthread_t				thread_id;
	pthread_mutex_t			*lock;
	pthread_mutex_t			*fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
}t_phil;

int		check_args(char **av);
int		error(int message);
int		ft_atoi(char *str);
void	*begin(void *ph);
void	ft_mutex_fork(t_phil *ph, char **av);
void	set_value(t_phil *ph, char **av);
void	*eat_time(t_phil *ph);
void	sleep_time(t_phil *ph);
void	think_time(t_phil *ph);
void	philo_died(t_phil *ph);
void	death_check(t_phil *ph);
int		eat_check(t_phil *ph);
int		my_sleep(t_phil *ph, size_t time);
int		*only_one(t_phil *ph);
void	ft_free(t_phil *ph);

#endif