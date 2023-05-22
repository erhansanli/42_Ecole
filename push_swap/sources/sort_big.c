/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:01 by esanli            #+#    #+#             */
/*   Updated: 2022/11/20 15:40:01 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(t_var	*sort, int i, int j, int k)
{
	i = 0;
	while (i < sort->digit)
	{
		j = 0;
		while (j < (sort->sa))
		{
			if (sort->a[0] >> i & 1)
				ra(sort);
			else
				pb(sort);
			j++;
		}
		k = 0;
		sort->sb = sort->size_b;
		while (k < sort->sb)
		{
			pa(sort);
			k++;
		}
		i++;
	}
}

void	big_sort(t_var *sort)
{
	sort->sa = sort->size_a;
	sort->sb = 0;
	sort->digit = 1;
	while (sort->sa - 1)
	{
		sort->digit++;
		sort->sa /= 2;
	}
	sort->sa = sort->size_a;
	radix(sort, 0, 0, 0);
}

void	take_index_fsa_cont(t_var *sort, int i, int count)
{
	count = 0;
	while (count < sort->size_a)
	{
		i = 0;
		sort->tmp = INT_MAX;
		while (i < sort->size_a)
		{
			if ((sort->a[i] < sort->tmp) && !sort->k[i])
				sort->tmp = sort->a[i];
			i++;
		}
		i = 0;
		while (sort->a[i] != sort->tmp)
			i++;
		count++;
		sort->k[i] = count;
	}
}

void	take_index_for_stack_a(t_var *sort)
{
	int		i;

	i = 0;
	sort->k = malloc(sizeof(int) * sort->size_a);
	while (i < sort->size_a)
		sort->k[i++] = 0;
	take_index_fsa_cont(sort, 0, 0);
	i = 0;
	while (i < sort->size_a)
	{
		sort->a[i] = sort->k[i];
		i++;
	}
	free (sort->k);
}
