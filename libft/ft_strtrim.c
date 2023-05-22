/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:43:34 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:14:09 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen (s1);
	while (s1[i] != '\0' && trimcheck(s1[i], set))
		i++;
	while (i < k && trimcheck(s1[k - 1], set))
		k--;
	newstr = (char *)malloc(sizeof(char) * (k - i) + 1);
	if (!newstr)
		return (NULL);
	while (i < k)
	{
		newstr[j++] = s1[i++];
	}
	newstr[j] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	const char	*str;
// 	const char	*str1;

// 	str = "___xxx_erhan_xxx___";
// 	str1 = "_x";
// 	printf("%s", ft_strtrim(str, str1));
// }
