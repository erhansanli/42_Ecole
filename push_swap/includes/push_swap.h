/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:48:11 by esanli            #+#    #+#             */
/*   Updated: 2022/11/23 14:43:39 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct var
{
	int		*a;
	int		*b;
	char	**str;
	int		size_a;
	int		size_b;
	int		tmp;
	int		digit;
	int		sa;
	int		sb;
	int		*k;
	int		sayim;
}t_var;

int		main(int ac, char **av);
void	take_arguments(char **av, t_var *sort);
void	arguments_control(t_var *sort, int i, int j);
void	equal_control(t_var *sort);
void	function_sort(t_var	*sort);
void	stack_a_load(t_var	*sort);
void	sort_control(t_var *sort);
void	ft_exit(void);
char	**ft_split(char *str);
int		count_words(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	sa(t_var *sort);
void	pa(t_var *sort);
void	ra(t_var *sort);
void	rra(t_var *sort);
void	sb(t_var *sort);
void	pb(t_var *sort);
void	rb(t_var *sort);
void	rrb(t_var *sort);
void	ss(t_var *sort);
void	rr(t_var *sort);
void	rrr(t_var *sort);
void	big_sort(t_var *sort);
void	take_index_for_stack_a(t_var *sort);
void	small_sort(t_var *sort);
void	three_sort(t_var *sort);
void	four_sort(t_var	*sort);
void	smallerfive_sort(t_var *sort);
int		min_index(t_var *sort);
void	push_swap_free(t_var *sort);
void	free_sort_str(t_var *sort);

#endif