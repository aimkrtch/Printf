/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:49:54 by aimkrtch          #+#    #+#             */
/*   Updated: 2023/02/08 20:36:13 by aimkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_d_i(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int i, const char str);
int		ft_print_p(unsigned long long int i);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif