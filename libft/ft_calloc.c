/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:57:01 by esanli            #+#    #+#             */
/*   Updated: 2022/04/25 17:01:25 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}

// int main ()
// {
//  	size_t		a;
//  	size_t		b;
//  	char	*s;

//  	a = 2;
//  	b = 5;
//     s = ft_calloc(a, b);
//  	printf("%p\n %s", s, s[0]);
// }
