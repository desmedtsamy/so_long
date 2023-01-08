/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:53:32 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 16:37:46 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define GHOST_2 "./sprites/ghost2.xmp"
# define PACMAN_CLOSE "./sprites/pacman/pacman_close.xmp"
# define PACMAN_SEMI_RIGHT "./sprites/pacman/pac_semi_right.xmp"
# define PACMAN_OPEN_RIGHT "./sprites/pacman/pac_open_right.xmp"
# define PACMAN_SEMI_LEFT "./sprites/pacman/pac_semi_left.xmp"
# define PACMAN_OPEN_LEFT "./sprites/pacman/pac_open_left.xmp"
# define PACMAN_SEMI_UP "./sprites/pacman/pac_semi_up.xmp"
# define PACMAN_OPEN_UP "./sprites/pacman/pac_open_up.xmp"
# define PACMAN_SEMI_DOWN "./sprites/pacman/pac_semi_down.xmp"
# define PACMAN_OPEN_DOWN "./sprites/pacman/pac_open_down.xmp"

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
	void	*enemy;
	void	*empty;
}				t_sprites;

typedef struct s_enemy
{
	t_vector	pos;
	char		old_value;
	t_vector	old_pos;
}				t_enemy;

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
	t_enemy		*enemies;
	t_player	player;
	int			number_enemies;
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
void	init_value(t_map *map);
void	init_ghosts(t_map *map);
void	set_sprites(t_game *game, t_sprites *sprites);
void	set_default_sprites(t_game *game, t_sprites *sprites);
void	update_enemies(t_game *game);
void	update_player(t_game *game);
int		quit(void *param);
#endif