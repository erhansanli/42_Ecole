/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:48:25 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 17:57:32 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mapcheck_wrongchar(t_var *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->linecount)
	{
		j = 0;
		while (j < game->columncount)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'P' \
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E' \
				&& game->map[i][j] != '0')
			{
				ft_printf("ERROR!!!\nWrong Character in Map!!!\n");
				free_game(game);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	first_location(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->linecount)
	{
		j = 0;
		while (j < game->columncount)
		{
			if (game->valid[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mapcheck_validpath1(t_var *game, int y, int x)
{
	if (game->valid[y][x] != '1')
	{
		if (game->valid[y][x] != 'E')
		{
			if (game->valid[y][x] == 'C')
				game->collect_valid--;
			game->valid[y][x] = 'P';
			if (game->valid[y][x + 1] != '1' && game->valid[y][x + 1] != 'P')
				mapcheck_validpath1(game, y, x + 1);
			if (game->valid[y][x - 1] != '1' && game->valid[y][x - 1] != 'P')
				mapcheck_validpath1(game, y, x - 1);
			if (game->valid[y + 1][x] != '1' && game->valid[y + 1][x] != 'P')
				mapcheck_validpath1(game, y + 1, x);
			if (game->valid[y - 1][x] != '1' && game->valid[y - 1][x] != 'P')
				mapcheck_validpath1(game, y - 1, x);
		}
		else
			game->exit_valid = 1;
	}
}

void	mapcheck_validpath(t_var *game)
{
	game->exit_valid = 0;
	game->collect_valid = game->collectable;
	first_location(game);
	mapcheck_validpath1(game, game->y, game->x);
	if (game->exit_valid != 1 || game->collect_valid != 0)
	{
		ft_printf("ERROR!!!\nValidPath\n");
		free_game(game);
		exit (0);
	}
}
