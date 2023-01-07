/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:13:02 by samy              #+#    #+#             */
/*   Updated: 2023/01/07 01:26:47 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_default_sprites(t_game *game, t_sprites *sprites)
{
	int		s;

	s = SIZE;
	sprites->wall = mlx_xpm_file_to_image(game->mlx, WALL, &s, &s);
	sprites->food = mlx_xpm_file_to_image(game->mlx, FOOD, &s, &s);
	sprites->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
	sprites->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &s, &s);
}

static void	set_img(void **sprite, t_game game, char *name)
{
	int		s;

	s = SIZE;
	*sprite = mlx_xpm_file_to_image(game.mlx, name, &s, &s);
}

static void	set_sprites_1(t_game *game, t_sprites *sprites)
{
	if (game->direction == 2)
		set_img(&sprites->pacman, *game, PACMAN_SEMI_RIGHT);
	else if (game->direction == 0)
		set_img(&sprites->pacman, *game, PACMAN_SEMI_LEFT);
	else if (game->direction == 13)
		set_img(&sprites->pacman, *game, PACMAN_SEMI_UP);
	else if (game->direction == 1)
		set_img(&sprites->pacman, *game, PACMAN_SEMI_DOWN);
	set_img(&sprites->enemy, *game, GHOST);
}

static void	set_sprites_2(t_game *game, t_sprites *sprites)
{
	if (game->direction == 2)
		set_img(&sprites->pacman, *game, PACMAN_OPEN_RIGHT);
	else if (game->direction == 0)
		set_img(&sprites->pacman, *game, PACMAN_OPEN_LEFT);
	else if (game->direction == 13)
		set_img(&sprites->pacman, *game, PACMAN_OPEN_UP);
	else if (game->direction == 1)
		set_img(&sprites->pacman, *game, PACMAN_OPEN_DOWN);
	set_img(&sprites->enemy, *game, GHOST_2);
}

void	set_sprites(t_game *game, t_sprites *sprites)
{
	if (game->update == 0)
	{
		set_img(&sprites->pacman, *game, PACMAN_CLOSE);
		set_img(&sprites->enemy, *game, GHOST);
		if (game->direction != 42)
			game->update = 1;
	}
	else if (game->update == 1)
	{
		set_sprites_1(game, sprites);
		game->update = 2;
	}
	else
	{
		set_sprites_2(game, sprites);
		game->update = 0;
	}
}
