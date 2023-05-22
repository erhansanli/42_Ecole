/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_functions_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:39:45 by esanli            #+#    #+#             */
/*   Updated: 2022/11/20 15:39:45 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_var *sort)
{
	if (sort->size_a >= 2)
	{
		sort->tmp = sort->a[1];
		sort->a[1] = sort->a[0];
		sort->a[0] = sort->tmp;
		write (1, "sa\n", 3);
	}
	else
		return ;
}

void	pa_continue(t_var *sort)
{
	sort->size_b--;
	sort->size_a++;
	sort->a[0] = sort->tmp;
	write (1, "pa\n", 3);
}

void	pa(t_var *sort)
{
	int		i;
	int		flag;
	int		a;

	i = -1;
	flag = 0;
	sort->tmp = sort->b[0];
	while (++i < sort->size_b)
	{
		sort->b[i] = sort->b[i + 1];
		flag = 1;
	}
	i = -1;
	a = sort->size_a;
	while ((++i < sort->size_a) && sort->size_b)
	{
		sort->a[a] = sort->a[a - 1];
		a--;
	}
	if (flag == 1)
		pa_continue(sort);
}

void	ra(t_var *sort)
{
	int		i;

	i = -1;
	sort->tmp = sort->a[0];
	if (sort->size_a >= 2)
	{
		while (++i < (sort->size_a - 1))
			sort->a[i] = sort->a[i + 1];
		sort->a[sort->size_a - 1] = sort->tmp;
		write (1, "ra\n", 3);
	}
	else
		return ;
}

void	rra(t_var *sort)
{
	int		i;
	int		a;

	i = -1;
	sort->tmp = sort->a[sort->size_a - 1];
	a = sort->size_a - 1;
	if (sort->size_a >= 2)
	{
		while (++i < (sort->size_a - 1))
		{
			sort->a[a] = sort->a[a - 1];
			a--;
		}
		sort->a[0] = sort->tmp;
		write (1, "rra\n", 4);
	}
	else
		return ;
}
