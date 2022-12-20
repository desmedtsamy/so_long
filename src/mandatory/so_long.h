/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:53:32 by samy              #+#    #+#             */
/*   Updated: 2022/12/20 10:09:52 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <libft.h>
# include <get_next_line_bonus.h>
# include <ft_printf.h>

# define DESTROYNOTIFY	17
# define SIZE	32
# define WALL "./sprites/wall.xmp"
# define PACMAN "./sprites/pacman.xmp"
# define FOOD "./sprites/food.xmp"
# define EXIT "./sprites/exit.xmp"

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
}				t_sprites;

typedef struct s_map
{
	int			row;
	int			column;
	int			spawn;
	int			food;
	int			exit;
	char		**map;
	t_vector	player;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			moves;
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