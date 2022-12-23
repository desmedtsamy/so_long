/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:53:32 by samy              #+#    #+#             */
/*   Updated: 2022/12/23 17:45:37 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <fcntl.h>

# define DESTROYNOTIFY	17
# define SIZE	32
# define WALL "./sprites/wall.xmp"
# define PACMAN "./sprites/pacman.xmp"
# define FOOD "./sprites/food.xmp"
# define EXIT "./sprites/exit.xmp"
# define ENEMY "./sprites/ghost.xmp"

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_sprites
{
	void	*wall;
	void	*player;
	void	*food;
	void	*exit;
	void	*enemy;
}				t_sprites;

typedef struct s_enemy
{
	t_vector	pos;
	char		old_value;
}				t_enemy;

typedef struct s_map
{
	int			row;
	int			column;
	int			spawn;
	int			food;
	int			exit;
	char		**map;
	t_enemy		*enemies;
	int			number_enemies;
	t_vector	player;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			frames;
	int			moves;
	char		*path;
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

#endif