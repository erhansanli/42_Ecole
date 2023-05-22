/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:24:21 by esanli            #+#    #+#             */
/*   Updated: 2022/04/25 16:51:28 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int	main(void)
// {
// 	char	c;
// 	int		fd;

// 	c = 'z';
// 	fd = open("test.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	ft_putchar_fd(c, fd);
// }
