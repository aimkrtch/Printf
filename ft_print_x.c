/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:16:20 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 20:35:56 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_print_x(unsigned int i, const char str)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "abcdef";
	if (i < 10)
		len += ft_print_c(i + '0');
	else if (i < 16 && str == 'X')
		len += ft_print_c(toupper(hex[i - 10]));
	else if (i < 16 && str == 'x')
		len += ft_print_c(hex [i - 10]);
	else
	{
		len += ft_print_x(i / 16, str);
		len += ft_print_x(i % 16, str);
	}
	return (len);
}
