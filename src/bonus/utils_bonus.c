/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:45 by sde-smed          #+#    #+#             */
/*   Updated: 2022/12/20 12:23:51 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
		free(map->map[i++]);
	free(map->map);
}

void	error(char *message, t_map *map)
{
	ft_printf("Error\n%s", message);
	if (map != NULL)
		free_map(map);
	exit(0);
}
