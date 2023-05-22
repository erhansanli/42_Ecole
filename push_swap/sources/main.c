/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:47:22 by esanli            #+#    #+#             */
/*   Updated: 2022/11/23 14:35:53 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	function_sort(t_var	*sort)
{
	if ((sort->size_a) <= 5)
		small_sort(sort);
	else
	{
		take_index_for_stack_a(sort);
		big_sort(sort);
	}
}

void	stack_a_load(t_var	*sort)
{
	int		i;

	i = 0;
	sort->size_a = sort->sayim;
	sort->size_b = 0;
	while (sort->sayim-- > 0)
	{
		sort->a[i] = ft_atoi(sort->str[i]);
		i++;
	}
	free_sort_str(sort);
}

void	take_arguments_2(char **av, t_var *sort, int i, int j)
{
	int		m;
	char	**num;

	while (av[i])
	{
		if (count_words(av[i]) > 1)
		{
			m = 0;
			num = ft_split(av[i]);
			while (num[m])
				sort->str[j++] = num[m++];
		}
		else
		{
			num = ft_split(av[i]);
			sort->str[j] = num[0];
			if (sort->str[j] == NULL)
				ft_exit();
			j++;
		}
		free(num);
		i++;
	}
	sort->str[j] = NULL;
}

void	take_arguments(char **av, t_var *sort)
{
	int		i;

	sort->sayim = 0;
	i = 1;
	while (av[i])
	{
		sort->sayim += count_words(av[i]);
		i++;
	}
	sort->str = malloc((sizeof(char *)) * (sort->sayim + 1));
	if (!sort->str)
		ft_exit();
	take_arguments_2(av, sort, 1, 0);
	sort->a = malloc(sizeof(int) * (sort->sayim));
	if (!sort->a)
		ft_exit();
	sort->b = malloc(sizeof(int) * (sort->sayim));
	if (!sort->b)
		ft_exit();
}

int	main(int ac, char **av)
{
	t_var	*sort;

	if (ac < 2)
		return (0);
	sort = malloc(sizeof(t_var));
	if (!sort)
		return (0);
	take_arguments(av, sort);
	arguments_control(sort, 0, 0);
	stack_a_load(sort);
	equal_control(sort);
	function_sort(sort);
	push_swap_free(sort);
}
