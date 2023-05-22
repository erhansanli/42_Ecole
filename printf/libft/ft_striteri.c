/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:29:37 by esanli            #+#    #+#             */
/*   Updated: 2022/04/15 20:13:30 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
	i++;
	}
}

// void	func(unsigned int i, char *a)
// {
// 	printf("%d. harf : %c\n", i + 1, *a);
// }

// int	main(void)
// {
// 	char *str = "baba";

// 	ft_striteri(str, func);
// }
