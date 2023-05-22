/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:25:10 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:12:50 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (len--)
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}

// int main ()
// {
// 	char dest[] = "erhan"; // ./a.out 
// 	char src[] = "sanli"; // sahan
// 	printf("%s", ft_memmove(dest, src, 2));
// }

// int	main(void)
// {
// 	char		str[]="HelloWorldandEarth";

// 	ft_memmove((str + 5), str, 10);
// 	printf("%s", str);
// }
