/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:51:50 by esanli            #+#    #+#             */
/*   Updated: 2022/06/27 19:53:38 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_control(char c, va_list list, int *r);

void	ft_put_char(unsigned char list, int *r);
void	ft_put_str(char *str, int *r);
void	ft_string_write(char *list, int *r);
void	ft_pointer_address(size_t list, char *hex, int *r);
void	ft_decimal_integer(int list, int *r);
void	ft_hexadecimal(unsigned int list, char *hex, int *r);
void	ft_unsigned_int(unsigned int list, int *r);

#endif