/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:45 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/10 12:33:58 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
		free(map->map[i++]);
	free(map->map);
	free(map->enemies);
}

void	error(char *message, t_map *map)
{
	ft_printf("Error\n%s", message);
	if (map != NULL)
		free_map(map);
	exit(0);
}
