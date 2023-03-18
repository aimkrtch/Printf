/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:42:15 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 20:34:26 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_all(const char *str, va_list arg, const char c)
{
	int	len;

	len = 0;
	if (str[1] == 'c')
		len += ft_print_c(va_arg(arg, int));
	else if (str[1] == 's')
		len += ft_print_s(va_arg(arg, char *));
	else if (str[1] == '%')
		len += write(1, "%", 1);
	else if (str[1] == 'd' || str[1] == 'i')
		len += ft_print_d_i(va_arg(arg, int));
	else if (str[1] == 'u')
		len += ft_print_u(va_arg(arg, unsigned int));
	else if (str[1] == 'x' || str[1] == 'X')
		len += ft_print_x((unsigned long long)va_arg(arg, unsigned int), c);
	else if (str[1] == 'p')
		len += ft_print_p(va_arg(arg, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str && str[i] && i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			len += ft_print_all(&str[i], arg, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
