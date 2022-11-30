/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:45 by sde-smed          #+#    #+#             */
/*   Updated: 2022/11/30 14:03:44 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	ft_printf("Error\n%s", message);
	exit(0);
}

void	free_map(t_map map)
{
	int	i;

	while (i < map.column)
		free(map.map[i++]);
	free(map.map);
}
