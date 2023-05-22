/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:42:59 by esanli            #+#    #+#             */
/*   Updated: 2022/09/14 16:26:58 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message(int signum)
{
	static int	binary;
	static int	bitshift;

	if (signum == SIGUSR1)
		binary |= 1 << (7 - bitshift);
	bitshift++;
	if (bitshift == 8)
	{
		ft_putchar_fd(binary, 1);
		binary = 0;
		bitshift = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "SERVER PID = ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, message);
	signal(SIGUSR2, message);
	while (1)
		pause();
}
