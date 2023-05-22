/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:34:39 by esanli            #+#    #+#             */
/*   Updated: 2022/10/17 14:49:27 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	action(t_var *game)
{
	mlx_key_hook(game->win, playeraction, game);
	mlx_hook(game->win, 17, 0, shutdown, game);
}

int	shutdown(t_var *game)
{
	mlx_destroy_image(game->mlx, game->imgw);
	mlx_destroy_image(game->mlx, game->imgs);
	mlx_destroy_image(game->mlx, game->imgc);
	mlx_destroy_image(game->mlx, game->imge);
	mlx_destroy_image(game->mlx, game->imgp);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit (0);
}

int	playeraction(int keycode, t_var *game)
{
	if (keycode == 13)
		action_w(game);
	if (keycode == 0)
		action_a(game);
	if (keycode == 1)
		action_s(game);
	if (keycode == 2)
		action_d(game);
	if (keycode == 53)
	{
		ft_printf("Game Closed!!!\n");
		shutdown(game);
	}
	return (0);
}

void	screen_put_step(t_var *game)
{
	char	*str;
	char	*secstr;

	secstr = ft_itoa(game->step);
	str = ft_strjoin("Step : ", secstr);
	free(secstr);
	mlx_string_put(game->mlx, game->win, 50, 50, 62207, str);
	free(str);
}

void	free_game(t_var *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	i = 0;
	while (game->valid[i])
		free(game->valid[i++]);
	free(game->map);
	free(game->valid);
	free(game);
}
