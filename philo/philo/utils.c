/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:09 by esanli            #+#    #+#             */
/*   Updated: 2023/03/10 13:34:57 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int message)
{
	if (message == ARG_COUNT)
		printf("Argument counts are wrong!!!\n");
	else if (message == ARG_CONTROL)
		printf("You entered a wrong argument!!!\n");
	return (1);
}

int	check_args(char **av)
{
	int	i;
	int	arg;

	arg = 1;
	if (ft_atoi(av[1]) == 0)
		return (0);
	while (av[arg])
	{
		i = 0;
		while (av[arg][i])
		{
			if (av[arg][i] >= '0' && av[arg][i] <= '9')
				i++;
			else
				return (0);
		}
		arg++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48) * sign;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		i++;
	}
	return (result);
}

void	ft_free(t_phil *ph)
{
	free(ph->stop_prog);
	free(ph->philo_ate);
	free(ph->lock);
	free(ph->fork);
	free(ph);
}
