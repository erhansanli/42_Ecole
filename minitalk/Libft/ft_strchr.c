/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:52:36 by esanli            #+#    #+#             */
/*   Updated: 2022/09/14 15:02:27 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = ft_strlen(s) + 1;
	while (i < j)
	{
		if ((s[i] == (char )c))
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
