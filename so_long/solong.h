/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:36 by esanli            #+#    #+#             */
/*   Updated: 2022/10/18 14:42:31 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 42

# include <stdio.h> 
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_var
{
	int			fd;
	char		**map;
	char		**valid;
	int			linecount;
	int			columncount;
	int			player;
	int			collectable;
	int			exit;
	int			x;
	int			y;
	int			exit_valid;
	int			collect_valid;
	void		*mlx;
	void		*win;
	void		*imgw;
	void		*imgc;
	void		*imgs;
	void		*imge;
	void		*imgp;
	void		*imgps;
	int			w;
	int			h;
	int			step;
}t_var;

char	*get_next_line(int fd);
char	*readline(char *record, int fd);
char	*savelinelen(char *record);
char	*get_line(char *record);
char	*ft_free(char *record, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*word_create(char const *s, int size, int i);
int		split_count(const char *s, char c);
void	mapcheck(t_var *game);
void	mapcheck_rectangel(t_var *game);
void	mapcheck_wall_1(t_var *game);
void	mapcheck_ecp(t_var *game);
void	mapcheck_ecp2(t_var *game);
void	mapcheck_wrongchar(t_var *game);
void	mapcheck_validpath(t_var *game);
void	first_location(t_var *game);
void	mapcheck_validpath1(t_var *game, int y, int x);
void	mapcreate(t_var *game);
void	mapcreate_render(t_var *game);
void	mapcreate_render2(t_var *game, int i, int j);
void	action(t_var *game);
int		playeraction(int keycode, t_var *game);
int		shutdown(t_var *game);
void	action_w(t_var *game);
void	action_a(t_var *game);
void	action_s(t_var *game);
void	action_d(t_var *game);
void	screen_put_step(t_var *game);
char	*ft_itoa(int n);
char	*makechar(char *str, int n, int strsize);
int		sizeint(int c);
void	ber_control(char **argv);
void	file_open(t_var *game, char **argv);
void	take_map(t_var *game);
void	take_map2(t_var *game, char *lines);
void	take_map_cont(t_var *game, char *lines, char *line);
void	free_game(t_var *game);

#endif