/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:03:29 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:13:48 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
	len++;
	return (len);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Merhaba Dunya";
// 	printf("%zu", ft_strlen(str));
// }
