/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:53:07 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 17:15:30 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h> // malloc icin
# include <unistd.h> // write icin
# include <fcntl.h> // fd icin
# include <stdio.h> // printf kullanımı icin 

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *dest, int data, size_t len);

#endif