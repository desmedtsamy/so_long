/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:53:32 by samy              #+#    #+#             */
/*   Updated: 2022/11/30 13:59:08 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "printf/ft_printf.h"

# define DESTROYNOTIFY	17

typedef struct s_map
{
	int			row;
	int			column;
	char		**map;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
}				t_game;

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	start_check(char *path, t_map map);
void	error(char *message);
void	free_map(t_map map);

#endif