/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:13:52 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 20:15:21 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned long long i)
{
	int		len;
	char	*str;

	len = 0;
	str = "abcdef";
	if (i < 10)
		len += ft_print_c(i + '0');
	else if (i < 16)
		len += ft_print_c(str[i - 10]);
	else
	{
		len += ft_hex(i / 16);
		len += ft_hex(i % 16);
	}
	return (len);
}

int	ft_print_p(unsigned long long int i)
{
	if (!i)
		return (write(1, "0x0", 3));
	else
	{
		write(1, "0x", 2);
		return (ft_hex(i) + 2);
	}
}
