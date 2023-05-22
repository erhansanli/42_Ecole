/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:58:54 by esanli            #+#    #+#             */
/*   Updated: 2022/11/23 14:12:44 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap_free(t_var *sort)
{
	free(sort->a);
	free(sort->b);
	free(sort);
}

void	free_sort_str(t_var *sort)
{
	int		i;

	i = 0;
	while (sort->str[i])
		free(sort->str[i++]);
	free(sort->str);
}
