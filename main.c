/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/11/28 14:19:09 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -I /usr/local/include main.c -L ./minilibx -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"
#include <stdio.h>

int	deal_mouse(int button, int x, int y, void *param)
{
	t_game	*game = (t_game *)param;

	mlx_clear_window(game->mlx, game->window);
	mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
	mlx_string_put(game->mlx, game->window, x, y, 0xFFFFFF,"coucou");
	return (0);
}

int	deal_keys(int keycode, void *param)
{
	t_game	*game = (t_game *)param;
	char	str[42];

	sprintf(str, "%d", keycode);
	if (keycode == 53){
		mlx_clear_window(game->mlx, game->window);
		mlx_string_put(game->mlx, game->window, 400, 300, 0xFFFFFF, "bye");
		mlx_destroy_window(game->mlx, game->window);
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_string_put(game->mlx, game->window, 400, 300, 0xFFFFFF, str);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 800, 600, "hello");
	mlx_mouse_hook(game.window, deal_mouse, &game);
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_loop(game.mlx);
	return (0);
}
