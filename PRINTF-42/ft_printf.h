/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:19:16 by faacar            #+#    #+#             */
/*   Updated: 2023/07/17 15:24:02 by faacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //va_list
# include <unistd.h> //write

int	ft_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long w, int i);
int	ft_putnbr_hex(unsigned int num, char n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *check, ...);
int	ft_format_check(va_list *args, char check);

#endif
