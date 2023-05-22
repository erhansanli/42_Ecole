/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:30:33 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 16:51:12 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	sizeint(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i = 1;
	while (c)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*makechar(char *str, int n, int strsize)
{
	int		nbr;
	int		i;

	i = strsize;
	while (strsize)
	{
		nbr = n % 10 + 48;
		str[--strsize] = nbr;
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		strsize;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	strsize = sizeint(n);
	str = (char *)malloc(sizeof(char) * (strsize + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		makechar(str, n, strsize);
		str[0] = '-';
	}
	else
	{
		makechar(str, n, strsize);
	}
	return (str);
}
