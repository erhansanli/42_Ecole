/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:20:23 by esanli            #+#    #+#             */
/*   Updated: 2022/11/23 14:36:57 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

void	arguments_control(t_var *sort, int i, int j)
{
	i = 0;
	while (sort->str[i])
	{
		j = 0;
		while (sort->str[i][j])
		{
			if (sort->str[i][0] == '-' || sort->str[i][0] == '+')
			{
				if (!(sort->str[i][1] >= '0' && sort->str[i][1] <= '9'))
					ft_exit();
				if (sort->str[i][j + 1] && (sort->str[i][j + 1] < '0'\
					|| sort->str[i][j + 1] > '9'))
					ft_exit();
			}
			if (sort->str[i][0] != '-' && sort->str[i][0] != '+')
			{
				if (sort->str[i][j] < '0' || sort->str[i][j] > '9')
					ft_exit();
			}
			j++;
		}
		i++;
	}
}

void	equal_control(t_var *sort)
{
	int		i;
	int		j;

	i = 0;
	while (i < sort->size_a)
	{
		j = 0;
		while (j < sort->size_a)
		{
			if (j != i)
			{
				if (sort->a[i] == sort->a[j])
					ft_exit();
			}
			j++;
		}
		i++;
	}
	sort_control(sort);
}

void	sort_control(t_var *sort)
{
	int		i;	
	int		temp;

	i = 0;
	temp = sort->a[0];
	while (i < sort->size_a)
	{
		if (temp <= sort->a[i])
			temp = sort->a[i];
		else
			break ;
		i++;
	}
	if (temp == sort->a[sort->size_a - 1])
		exit(EXIT_SUCCESS);
}
