/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_functions_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:17 by esanli            #+#    #+#             */
/*   Updated: 2022/11/20 15:40:17 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_var *sort)
{
	if (sort->size_b >= 2)
	{
		sort->tmp = sort->b[1];
		sort->b[1] = sort->b[0];
		sort->b[0] = sort->tmp;
		write (1, "sb\n", 3);
	}
	else
		return ;
}

void	pb_continue(t_var *sort)
{
	sort->size_a--;
	sort->size_b++;
	sort->b[0] = sort->tmp;
	write (1, "pb\n", 3);
}

void	pb(t_var *sort)
{
	int		i;
	int		flag;
	int		b;

	i = -1;
	flag = 0;
	sort->tmp = sort->a[0];
	while (++i < sort->size_a - 1)
	{
		sort->a[i] = sort->a[i + 1];
		flag = 1;
	}
	i = -1;
	b = sort->size_b;
	while ((++i < sort->size_b) && sort->size_a)
	{
		sort->b[b] = sort->b[b - 1];
		b--;
	}
	if (flag == 1)
		pb_continue(sort);
}

void	rb(t_var *sort)
{
	int		i;

	i = -1;
	sort->tmp = sort->b[0];
	if (sort->size_b >= 2)
	{
		while (++i < (sort->size_b - 1))
			sort->b[i] = sort->b[i + 1];
		sort->b[sort->size_b - 1] = sort->tmp;
		write (1, "rb\n", 3);
	}
	else
		return ;
}

void	rrb(t_var *sort)
{
	int		i;
	int		b;

	i = -1;
	sort->tmp = sort->b[sort->size_b - 1];
	b = sort->size_b - 1;
	if (sort->size_b >= 2)
	{
		while (++i < (sort->size_b - 1))
		{
			sort->b[b] = sort->b[b - 1];
			b--;
		}		
		sort->b[0] = sort->tmp;
		write (1, "rrb\n", 4);
	}
	else
		return ;
}
