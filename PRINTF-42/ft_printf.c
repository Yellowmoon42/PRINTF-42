/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:19:19 by faacar            #+#    #+#             */
/*   Updated: 2023/07/17 15:39:30 by faacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf(const char *check, ...)
{
	va_list	ar;
	int		printed;
	int		index;
	int		result;

	va_start(ar, check);
	printed = 0;
	index = -1;
	while (check[++index] != '\0')
	{
		if (check[index] == '%')
		{
			result = ft_format_check(&ar, check[index + 1]);
			if (result == -1)
				return (-1);
			printed += (result - 1);
			index++;
		}
		else if (ft_putchar(check[index]) == -1)
			return (-1);
		printed++;
	}
	va_end(ar);
	return (printed);
}

int	ft_format_check(va_list *args, char check)
{
	if (check == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (check == '%')
		return (ft_putchar('%'));
	else if (check == 'd' || check == 'i')
		return (ft_putnbr(va_arg((*args), int)));
	else if (check == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (check == 's')
		return (ft_putstr(va_arg((*args), char *)));
	else if (check == 'X' || check == 'x')
		return (ft_putnbr_hex(va_arg((*args), unsigned int), check));
	else if (check == 'p')
		return (ft_putptr(va_arg((*args), unsigned long), 1));
	else
		return (0);
}
