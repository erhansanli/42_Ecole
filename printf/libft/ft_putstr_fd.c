/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:30:29 by esanli            #+#    #+#             */
/*   Updated: 2022/04/25 16:58:54 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i++], 1);
	}
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	str = "abc";
// 	fd = open("test.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	ft_putstr_fd(str, fd);
// 	close(fd);
// }
