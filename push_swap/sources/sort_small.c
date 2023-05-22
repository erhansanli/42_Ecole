/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:09 by esanli            #+#    #+#             */
/*   Updated: 2022/11/20 15:40:09 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_var *sort)
{
	if ((sort->a[2] > sort->a[0]) && (sort->a[1] < sort->a[0]))
		sa(sort);
	else if ((sort->a[0] > sort->a[1]) && (sort->a[1] > sort->a[2]))
	{
		sa(sort);
		rra(sort);
	}
	else if ((sort->a[0] > sort->a[2]) && (sort->a[2] > sort->a[1]))
		ra(sort);
	else if ((sort->a[0] < sort->a[2]) && (sort->a[2] < sort->a[1]))
	{
		sa(sort);
		ra(sort);
	}
	else if ((sort->a[2] < sort->a[0]) && (sort->a[0] < sort->a[1]))
		rra(sort);
}

int	min_index(t_var *sort)
{
	int		i;

	i = 1;
	sort->tmp = sort->a[0];
	while (i < sort->size_a)
	{
		if (sort->a[i] < sort->tmp)
			sort->tmp = sort->a[i];
		i++;
	}
	i = 0;
	while (sort->a[i] != sort->tmp)
		i++;
	return (i);
}

void	four_sort(t_var	*sort)
{
	int		i;

	i = min_index(sort);
	if (i == 1)
		ra(sort);
	else if (i == 2)
	{
		ra(sort);
		ra(sort);
	}
	else if (i == 3)
		rra(sort);
	pb(sort);
	three_sort(sort);
	pa(sort);
}

void	smallerfive_sort(t_var *sort)
{
	int		i;

	i = min_index(sort);
	if (i == 1)
		ra(sort);
	else if (i == 2)
	{
		ra(sort);
		ra(sort);
	}
	else if (i == 3)
	{
		rra(sort);
		rra(sort);
	}
	else if (i == 4)
		rra(sort);
	pb(sort);
	four_sort(sort);
	pa(sort);
}

void	small_sort(t_var *sort)
{
	if (sort->size_a == 2)
	{
		if (sort->a[0] > sort->a[1])
			sa(sort);
	}
	else if (sort->size_a == 3)
		three_sort(sort);
	else if (sort->size_a == 4)
		four_sort(sort);
	else if (sort->size_a == 5)
		smallerfive_sort(sort);
}
