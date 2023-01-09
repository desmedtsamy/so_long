/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:45 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/08 13:47:06 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
