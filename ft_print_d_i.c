/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:17:59 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 17:03:14 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchr(int c)
{
	return (write(1, &c, 1));
}

static int	putnbr(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = n;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nbr < 0)
	{
		len += putchr('-');
		nbr = -nbr;
		len += putnbr(nbr);
	}
	else if (nbr > 9)
	{
		len += putnbr(nbr / 10);
		len += putnbr(nbr % 10);
	}
	else
		len += putchr(nbr + 48);
	return (len);
}

int	ft_print_d_i(int n)
{
	return (putnbr(n));
}
