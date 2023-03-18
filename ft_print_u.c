/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:16:44 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 16:36:25 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchr(int c)
{
	return (write(1, &c, 1));
}

static int	putnbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += putnbr(nbr / 10);
		len += putnbr(nbr % 10);
	}
	else
		len += putchr(nbr + 48);
	return (len);
}

int	ft_print_u(unsigned int n)
{
	return (putnbr(n));
}
