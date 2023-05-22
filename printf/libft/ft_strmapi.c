/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:06:10 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:13:52 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;
	size_t			j;

	if (!s || !f)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * j + 1);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// char	f(unsigned int a, char b)
// {
// 	if (a > 0)
// 		b = b + 1;
// 	return (b);
// }

// int	main(void)
// {
// 	char	*str;

// 	str = "erhan";
// 	printf("%s", ft_strmapi(str, f));
// }
