/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:53:10 by esanli            #+#    #+#             */
/*   Updated: 2022/04/25 16:53:47 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i++], 1);
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char str[] = "erhan";
// 	int fd;

// 	fd = open("test.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	ft_putendl_fd(str, fd);
// }
