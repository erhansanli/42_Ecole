/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:46:20 by esanli            #+#    #+#             */
/*   Updated: 2022/06/27 19:59:29 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(unsigned char list, int *r)
{
	*r += write(1, &list, 1);
}

void	ft_put_str(char *str, int *r)
{
	while (*str)
	{
		*r += write(1, str, 1);
		str++;
	}
}

void	ft_string_write(char *list, int *r)
{
	if (!list)
	{
		ft_string_write("(null)", r);
		return ;
	}
	ft_put_str(list, r);
}

void	ft_pointer_address(size_t list, char *hex, int *r)
{
	char	s[16];
	int		i;

	i = 0;
	if (!list)
	{
		*r += write(1, "0x0", 3);
		return ;
	}
	ft_bzero(s, 16);
	while (list)
	{
		s[i++] = hex[list % 16];
		list /= 16;
	}
	*r += write(1, "0x", 2);
	while (i--)
		*r += write(1, s + i, 1);
}
