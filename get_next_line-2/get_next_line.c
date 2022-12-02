/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:53:23 by sde-smed          #+#    #+#             */
/*   Updated: 2022/11/11 10:06:41 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_result(char *str)
{
	char	*result;
	int		count;
	int		i;

	count = 0;
	i = -1;
	if (!str[0])
		return (ft_free(&str));
	while (str[count] && str[count] != '\n')
		count++;
	if (str[count])
		count++;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (++i < count)
		result[i] = str[i];
	result[count] = 0;
	return (result);
}

static char	*set_str(char *str)
{
	char	*new_str;
	int		count;
	int		i;

	count = 0;
	if (!str)
		return (ft_free(&str));
	while (str[count] && str[count] != '\n')
		count++;
	if (!str[count])
		return (ft_free(&str));
	count++;
	if (!(ft_strlen(str) - count))
		return (ft_free(&str));
	new_str = malloc(((ft_strlen(str) - count) + 1) * sizeof(char));
	if (!new_str)
		return (ft_free(&str));
	i = 0;
	while (str[count])
		new_str[i++] = str[count++];
	new_str[i] = 0;
	free(str);
	return (new_str);
}

static char	*read_fd(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read;

	nb_read = 1;
	while (!ft_strchr(str, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (ft_free(&str));
		if (nb_read == 0)
			return (str);
		buffer[nb_read] = 0;
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_free(&str));
	str = read_fd(fd, str);
	if (!str)
		return (ft_free(&str));
	result = set_result(str);
	if (!result)
		return (ft_free(&str));
	str = set_str(str);
	return (result);
}
