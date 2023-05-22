/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:06:59 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 17:32:49 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	action_w(t_var *game)
{
	if (game->map[game->y - 1][game->x] == '0')
	{
		game->map[game->y - 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		game->y--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y - 1][game->x] == 'C')
	{
		game->map[game->y - 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		game->y--;
		game->collectable--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y - 1][game->x] == 'E' && game->collectable == 0)
	{
		ft_printf("Step : %d\n", ++game->step);
		ft_printf("Mission Completed!!!\n");
		shutdown(game);
	}
	mapcreate_render(game);
}

void	action_a(t_var *game)
{
	if (game->map[game->y][game->x - 1] == '0')
	{
		game->map[game->y][game->x - 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->x--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y][game->x - 1] == 'C')
	{
		game->map[game->y][game->x - 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->x--;
		game->collectable--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y][game->x - 1] == 'E' && game->collectable == 0)
	{
		ft_printf("Step : %d\n", ++game->step);
		ft_printf("Mission Completed!!!\n");
		shutdown(game);
	}
	mapcreate_render(game);
}

void	action_s(t_var *game)
{
	if (game->map[game->y + 1][game->x] == '0')
	{
		game->map[game->y + 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		game->y++;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y + 1][game->x] == 'C')
	{
		game->map[game->y + 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		game->y++;
		game->collectable--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y + 1][game->x] == 'E' && game->collectable == 0)
	{
		ft_printf("Step : %d\n", ++game->step);
		ft_printf("Mission Completed!!!\n");
		shutdown(game);
	}
	mapcreate_render(game);
}

void	action_d(t_var *game)
{
	if (game->map[game->y][game->x + 1] == '0')
	{
		game->map[game->y][game->x + 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->x++;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y][game->x + 1] == 'C')
	{
		game->map[game->y][game->x + 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->x++;
		game->collectable--;
		ft_printf("Step : %d\n", ++game->step);
	}
	else if (game->map[game->y][game->x + 1] == 'E' && game->collectable == 0)
	{
		ft_printf("Step : %d\n", ++game->step);
		ft_printf("Mission Completed!!!\n");
		shutdown(game);
	}
	mapcreate_render(game);
}
