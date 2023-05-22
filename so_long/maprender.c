/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maprender.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:27:38 by esanli            #+#    #+#             */
/*   Updated: 2022/10/17 14:27:29 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mapcreate(t_var *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
		64 * game->columncount, 64 * game->linecount, "so_long");
	game->imgw = mlx_xpm_file_to_image(game->mlx, \
		"./images/wall.xpm", &game->w, &game->h);
	game->imgc = mlx_xpm_file_to_image(game->mlx, \
		"./images/collectable.xpm", &game->w, &game->h);
	game->imgs = mlx_xpm_file_to_image(game->mlx, \
		"./images/space.xpm", &game->w, &game->h);
	game->imgp = mlx_xpm_file_to_image(game->mlx, \
		"./images/demon.xpm", &game->w, &game->h);
	game->imge = mlx_xpm_file_to_image(game->mlx, \
		"./images/exit.xpm", &game->w, &game->h);
	game->step = 0;
	mapcreate_render(game);
}

void	mapcreate_render(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->linecount)
	{
		j = 0;
		while (j < game->columncount)
		{
			mapcreate_render2(game, i, j);
			j++;
		}
		i++;
	}
	screen_put_step(game);
}

void	mapcreate_render2(t_var *game, int i, int j)
{
	if (game->map[i][j])
		mlx_put_image_to_window(game->mlx, \
			game->win, game->imgs, j * 64, i * 64);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->imgw, j * 64, i * 64);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->imgc, j * 64, i * 64);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->imgp, j * 64, i * 64);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, \
			game->win, game->imge, j * 64, i * 64);
}
