/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:53:32 by samy              #+#    #+#             */
/*   Updated: 2023/01/10 12:22:04 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <fcntl.h>

# define FRAMES	850
# define DESTROYNOTIFY	17
# define SIZE	32
# define WALL "./sprites/wall.xmp"
# define FOOD "./sprites/food.xmp"
# define EXIT "./sprites/exit.xmp"
# define GHOST "./sprites/ghost.xmp"
# define PACMAN "./sprites/pacman/pac_semi_right.xmp"
# define EMPTY "./sprites/empty.xmp"

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_sprites
{
	void	*wall;
	void	*pacman;
	void	*food;
	void	*exit;
	void	*empty;
}				t_sprites;

typedef struct s_player
{
	t_vector	pos;
	t_vector	old_pos;
	int			new_direction;
	int			current_direction;
	int			old_direction;
}				t_player;

typedef struct s_map
{
	int			row;
	int			column;
	int			spawn;
	int			food;
	int			exit;
	char		**map;
	t_player	player;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			moves;
	char		*path;
	char		update;
	int			frames;
	t_map		map;
	t_sprites	sprites;
}				t_game;

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	start_check(char *path, t_map *map);
void	error(char *message, t_map *map);
void	render_map(t_game *game);
void	put_image(t_game game);
int		can_win(t_map map);
int		check_wall(t_map map);
void	set_default_sprites(t_game *game, t_sprites *sprites);
void	render_map_2(t_game *game);
int		init_value(t_map *map);
void	set_sprites(t_game *game, t_sprites *sprites);
void	set_default_sprites(t_game *game, t_sprites *sprites);
void	update_player(t_game *game);
int		quit(void *param);
void	free_map(t_map *map);
#endif