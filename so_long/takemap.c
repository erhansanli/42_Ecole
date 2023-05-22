/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:48:48 by esanli            #+#    #+#             */
/*   Updated: 2022/10/18 15:48:24 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	take_map2(t_var *game, char *lines)
{
	game->map = ft_split(lines, '\n');
	if (!game->map)
	{
		free(lines);
		close(game->fd);
		free(game);
		ft_printf("ERROR!!!\nMap didn't create\n");
		exit (0);
	}
	game->valid = ft_split(lines, '\n');
	game->columncount = ft_strlen(game->map[0]);
	close(game->fd);
	free(lines);
}

void	take_map_cont(t_var *game, char *lines, char *line)
{
	ft_printf("ERROR!!!\nMap is Wrong\n");
	free(line);
	free(lines);
	close(game->fd);
	free(game);
	exit (0);
}

void	take_map(t_var *game)
{
	char	*lines;
	char	*line;

	lines = ft_strdup("");
	line = get_next_line(game->fd);
	if (!line)
		take_map_cont(game, lines, line);
	game->linecount = 0;
	while (line)
	{
		if (*line == '\n')
			take_map_cont(game, lines, line);
		lines = ft_free(lines, line);
		game->linecount++;
		free(line);
		line = get_next_line(game->fd);
	}
	take_map2(game, lines);
}
