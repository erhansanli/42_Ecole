/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:31:33 by esanli            #+#    #+#             */
/*   Updated: 2022/07/05 19:44:37 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal_integer(int list, int *r)
{
	if (list == -2147483648)
	{
		ft_put_str("-2147483648", r);
		return ;
	}
	else
	{
		if (list < 0)
		{	
			ft_put_char('-', r);
			list *= -1;
		}
		if (list > 9)
			ft_decimal_integer(list / 10, r);
		ft_put_char(list % 10 + '0', r);
	}
}

void	ft_hexadecimal(unsigned int list, char *hex, int *r)
{
	char	s[8];
	int		i;

	i = 0;
	if (!list)
	{
		*r += write(1, "0", 1);
		return ;
	}
	while (list)
	{
		s[i++] = hex[list % 16];
		list /= 16;
	}
	while (i--)
		*r += write(1, s + i, 1);
}

void	ft_unsigned_int(unsigned int list, int *r)
{
	if (list > 9)
		ft_unsigned_int(list / 10, r);
	ft_put_char(list % 10 + '0', r);
}

int	ft_control(char c, va_list list, int *r)
{
	if (c == 'c')
		ft_put_char(va_arg(list, int), r);
	else if (c == 's')
		ft_string_write(va_arg(list, char *), r);
	else if (c == 'p')
		ft_pointer_address(va_arg(list, size_t), "0123456789abcdef", r);
	else if (c == 'd')
		ft_decimal_integer(va_arg(list, int), r);
	else if (c == 'i')
		ft_decimal_integer(va_arg(list, int), r);
	else if (c == 'u')
		ft_unsigned_int(va_arg(list, unsigned int), r);
	else if (c == 'x')
		ft_hexadecimal(va_arg(list, unsigned int), "0123456789abcdef", r);
	else if (c == 'X')
		ft_hexadecimal(va_arg(list, unsigned int), "0123456789ABCDEF", r);
	else if (c == '%')
		*r += write(1, "%", 1);
	else
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{	
	va_list	list;
	int		r;
	int		click;

	va_start(list, str);
	r = 0;
	click = 0;
	while (*str)
	{
		if (*str == '%')
		{
			while (*++str == ' ')
				click = 1;
			if (click && (*str == 'i' || *str == 'd'))
				r += write(1, " ", 1);
				click = 0;
			if (ft_control(*str, list, &r) == 1)
				r += write(1, str, 1);
		}
		else
			r += write(1, str, 1);
	str++;
	}
	va_end(list);
	return (r);
}
