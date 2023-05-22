/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:43:06 by esanli            #+#    #+#             */
/*   Updated: 2022/09/16 16:09:34 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *argv)
{
	int		i;
	int		j;

	i = 7;
	j = 0;
	while (argv[j])
	{
		if (argv[j] >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	i--;
		if (i == -1)
		{
			i = 7;
			j++;
		}
		usleep (100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		write(1, "!!!Write 2 Arguments!!! Server PID and One String", 50);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (0);
	send_signals(pid, argv[2]);
	send_signals(pid, "\n");
	return (0);
}
