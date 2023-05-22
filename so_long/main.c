/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:53 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 17:45:58 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ber_control(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' \
			|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
	{
		ft_printf("Error!!!\nGame filename hasn't extension .ber\n");
		exit (0);
	}
}

void	file_open(t_var *game, char **argv)
{
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("ERROR!!!\nFile didn't open, \
		File_path or File_name is wrong\n");
		close(game->fd);
		free(game);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_var	*game;

	if (argc != 2)
	{
		ft_printf("Error!!!\nOnly write 1 argument; with extension .ber\n");
		return (0);
	}
	ber_control(argv);
	game = malloc (sizeof(t_var));
	if (!game)
		return (0);
	file_open(game, argv);
	take_map(game);
	mapcheck(game);
	mapcreate(game);
	action(game);
	mlx_loop(game->mlx);
	return (0);
}
