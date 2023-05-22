/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:59:30 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:14:05 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if ((s[i] == (char )c))
			return ((char *)s + i);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	int		s;

// 	str = "erhan sanli";
// 	s = 'n';
// 	printf("%s", (ft_strrchr(str, s)));
// }
