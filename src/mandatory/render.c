/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:53:52 by sde-smed          #+#    #+#             */
/*   Updated: 2022/12/20 09:52:01 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(int x, int y, t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	w = y * SIZE;
	h = x * SIZE;
	if (game->map.map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->window, sprites->wall, w, h);
	else if (game->map.map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, sprites->player, w, h);
	else if (game->map.map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, sprites->food, w, h);
	else if (game->map.map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, sprites->exit, w, h);
}

void	set_sprites(t_game *game, t_sprites *sprites)
{
	int		s;

	s = SIZE;
	sprites->wall = mlx_xpm_file_to_image(game->mlx, WALL, &s, &s);
	sprites->player = mlx_xpm_file_to_image(game->mlx, PACMAN, &s, &s);
	sprites->food = mlx_xpm_file_to_image(game->mlx, FOOD, &s, &s);
	sprites->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
}

void	print_score(t_game game)
{
	mlx_string_put ( game.mlx, game.window, (game.map.column * SIZE)/2, game.map.row * SIZE + 21, 0xccccff, "42" );
}

void	render_map(t_game *game)
{
	t_vector	p;
	t_sprites	*sprites;

	sprites = &game->sprites;
	p.x = 0;
	set_sprites(game, &game->sprites);
	mlx_clear_window(game->mlx, game->window);
	while (p.x < game->map.row)
	{
		p.y = 0;
		while (p.y < game->map.column)
			print(p.x, p.y++, game, sprites);
		p.x++;
	}
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.player);
	mlx_destroy_image(game->mlx, game->sprites.food);
	mlx_destroy_image(game->mlx, game->sprites.exit);
	ft_printf("%d\n", game->moves);
	print_score(*game);
}
