/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:16:03 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:12:54 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	char	str[] = "GeeksForGeeks is for programming geeks.";

// 	printf("\nBefore memset(): %s\n", str);
// 	ft_memset(str + 13, '.', 8 * sizeof(char));
// 	printf("After memset():  %s", str);
// 	return (0);
// }
