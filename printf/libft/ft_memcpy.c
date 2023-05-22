/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:42:16 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:12:45 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
	}
	return (dst);
}

// int main()
// {
// 	char	dst[]="Merhaba Televole";
// 	char	src[]="abcefghij";
// 	ft_memcpy(dst, src, 5);
// 	printf("%s", dst);
// }

// int	main(void)
// {
// 	char	str[]="HelloWorldandEarth"; 

// 	ft_memcpy((str + 5), str, 10);
// 	printf("%s", str);//HelloHelloHellorth çakışma olur üstüne yazar
// }
