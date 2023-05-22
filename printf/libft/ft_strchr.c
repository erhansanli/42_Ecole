/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:52:36 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:13:22 by esanli           ###   ########.fr       */
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

// int	main(void)
// {
// 	char	*str;
// 	int		s;

// 	str = "erhan sanli";
// 	s = 'n';
// 	printf("%s", (ft_strchr(str, s)));
// }
