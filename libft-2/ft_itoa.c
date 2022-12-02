/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:32:40 by samy              #+#    #+#             */
/*   Updated: 2022/11/30 10:55:14 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_nbr(int nb, int *count)
{
	if (nb < 10)
		*count += 1;
	else
	{
		count_nbr(nb / 10, count);
		count_nbr(nb % 10, count);
	}
}

static void	ft_putnbr(int nb, char **result)
{
	if (nb < 10)
	{
		**result = nb + '0';
		*result += 1;
	}
	else
	{
		ft_putnbr(nb / 10, result);
		ft_putnbr(nb % 10, result);
	}
}

char	*ft_itoa(int n)
{
	int		negatif;
	char	*result;
	char	*tmp;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negatif = 0;
	if (n < 0)
	{
		negatif = 1;
		n *= -1;
	}
	count = 0;
	count_nbr(n, &count);
	result = malloc((count + negatif + 1) * sizeof(char));
	if (!result)
		return (0);
	if (negatif)
		*result = '-';
	tmp = &result[negatif];
	ft_putnbr(n, &tmp);
	result[(count + negatif)] = 0;
	return (result);
}
