/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:15:31 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:12:11 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main()
// {
// 	int arr[3] = {1, 123, 59};
// 	ft_bzero(&arr, 4); // int 4 byte olduğundan sadece ilk değer 0 olur.
// 	printf("%d %d %d" ,arr[0], arr[1], arr[2]);
// }
