/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:14:03 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 17:59:39 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mapcheck(t_var *game)
{
	mapcheck_rectangel(game);
	mapcheck_wall_1(game);
	mapcheck_ecp(game);
	mapcheck_wrongchar(game);
	mapcheck_validpath(game);
}

void	mapcheck_rectangel(t_var *game)
{
	int	i;
	int	column;

	i = 0;
	column = 0;
	while (game->map[i])
	{
		column = ft_strlen(game->map[i]);
		if (game->columncount != column || game->linecount < 2)
		{
			ft_printf("ERROR!!!\nMap is not Rectengal\n");
			free_game(game);
			exit(0);
		}
		i++;
	}
}

void	mapcheck_wall_1(t_var *game)
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
			if (game->map[0][j] != '1' \
				|| game->map[game->linecount - 1][j] != '1' \
				|| game->map[i][0] != '1' \
				|| game->map[i][game->columncount - 1] != '1')
			{
				ft_printf("ERROR!!!\nMap_Walls are not 1\n");
				free_game(game);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	mapcheck_ecp(t_var *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->player = 0;
	game->exit = 0;
	game->collectable = 0;
	while (i < game->linecount)
	{
		j = 0;
		while (j < game->columncount)
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collectable++;
			j++;
		}
		i++;
	}
	mapcheck_ecp2(game);
}

void	mapcheck_ecp2(t_var *game)
{
	if (game->player != 1)
	{
		ft_printf("ERROR!!!\nPlayer_count is wrong\n");
		free_game(game);
		exit(0);
	}
	if (game->exit != 1)
	{
		ft_printf("ERROR!!!\nExit_count is wrong\n");
		free_game(game);
		exit(0);
	}
	if (game->collectable < 1)
	{
		ft_printf("ERROR!!!\nCollectables less than 1\n");
		free_game(game);
		exit(0);
	}
}
