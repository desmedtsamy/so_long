/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/12/05 14:53:29 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -I /usr/local/include main.c -L ./minilibx -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"
#include <stdio.h>

int	deal_mouse(int button, int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
	mlx_string_put(game->mlx, game->window, x, y, 0xFFFFFF, "coucou");
	return (0);
}

int	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	render_map(t_game game)
{
	int		x;
	int		y;
	int		size;
	void	*wall;
	void	*player;
	void	*food;

	x = 0;
	y = 0;
	size = SIZE;
	wall = mlx_xpm_file_to_image(game.mlx, "./sprites/wall.xmp", &size, &size);
	player = mlx_xpm_file_to_image(game.mlx, "./sprites/pacman.xmp", &size, &size);
	food = mlx_xpm_file_to_image(game.mlx, "./sprites/food.xmp", &size, &size);
	while (x < game.map.row)
	{
		y = 0;
		while (y < game.map.column)
		{
			if (game.map.map[x][y] == '1')
				mlx_put_image_to_window(game.mlx, game.window, wall, y * SIZE, x * SIZE);
			if (game.map.map[x][y] == 'E')
				mlx_put_image_to_window(game.mlx, game.window, player, y * SIZE, x * SIZE);
			if (game.map.map[x][y] == 'C')
				mlx_put_image_to_window(game.mlx, game.window, food, y * SIZE, x * SIZE);
			y++;
		}
		x++;
	}
	mlx_destroy_image(game.mlx, wall);
	mlx_destroy_image(game.mlx, player);
	mlx_destroy_image(game.mlx, food);
}

int	deal_keys(int keycode, void *param)
{
	t_game	*game;
	char	str[42];

	game = (t_game *)param;
	sprintf(str, "%d", keycode);
	if (keycode == 53)
		quit(param);
	if (keycode == 124)
	{
		int x = game->map.player.x;
		int y = game->map.player.y;
		printf("=-%d- %d %d=",game->map.map[x][y-1] != '1', x, y);
		if (game->map.map[x][y+1] != '1')
		{
			game->map.map[x][y] = '0';
			game->map.map[x][y+1] = 'E';
			game->map.player.y = ++y;
			mlx_clear_window(game->mlx, game->window);
			render_map(*game);
		}
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_string_put(game->mlx, game->window, 400, 300, 0xFFFFFF, str);
	}
	return (0);
}

void	put_image(t_game game)
{
	int		size;
	void	*img;

	size = SIZE;
	img = mlx_xpm_file_to_image(game.mlx, "./sprites/pacman.xmp", &size, &size);
	mlx_put_image_to_window(game.mlx, game.window, img, 400, 300);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		error("no map in arguments");
	if (argc > 2)
		error("to much arguments");
	start_check(argv[1], &game.map);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.column * SIZE, game.map.row * SIZE, "pacman_42");
	mlx_mouse_hook(game.window, deal_mouse, &game);
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_hook(game.window, DESTROYNOTIFY, 0, quit, &game);
	render_map(game);
	mlx_loop(game.mlx);
	return (0);
}
