/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:51:11 by sde-smed          #+#    #+#             */
/*   Updated: 2022/10/29 15:39:55 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_ul(unsigned long n);
int		put_hexa(unsigned long nb, char *base);
int		print_address(unsigned long nb);
int		print_hex(unsigned int nb, const char format);
int		ft_printf(const char *str, ...);
#endif