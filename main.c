/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/11/27 22:28:10 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -I /usr/local/include main.c -L ./minilibx -lmlx -framework OpenGL -framework AppKit

#include "so_long.h"
#include <unistd.h>

int	deal_mouse(int button, int x, int y, void *param)
{
	t_game	*game = (t_game *)param;
	mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1920, 1080, "hello");
	mlx_mouse_hook(game.window, deal_mouse, &game);
	mlx_loop(game.mlx);
}
