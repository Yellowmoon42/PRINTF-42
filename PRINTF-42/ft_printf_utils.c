/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:23:37 by faacar            #+#    #+#             */
/*   Updated: 2023/07/17 14:34:42 by faacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	index;

	index = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++index])
	{
		if (write(1, &str[index], 1) == -1)
			return (-1);
	}
	return (index);
}

int	ft_unsigned(unsigned int n)
{
	int	length;
	int	result;

	length = 0;
	if (n >= 10)
	{
		result = ft_unsigned(n / 10);
		if (result == -1)
			return (-1);
		length += result;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (length + 1);
}

int	ft_putnbr(int n)
{
	int	length;
	int	result;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		length++;
		n *= -1;
	}
	if (n >= 10)
	{
		result = ft_putnbr(n / 10);
		if (result == -1)
			return (-1);
		length += result;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (length + 1);
}

int	ft_putptr(unsigned long w, int i)
{
	int	length;
	int	result;

	length = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		length += 2;
	}
	if (w >= 16)
	{
		result = ft_putptr(w / 16, i);
		if (result == -1)
			return (-1);
		length += result;
	}
	if (write(1, &"0123456789abcdef"[w % 16], 1) == -1)
		return (-1);
	return (length + 1);
}

int	ft_putnbr_hex(unsigned int num, char n)
{
	int	length;
	int	result;

	length = 0;
	if (num >= 16)
	{
		result = ft_putnbr_hex(num / 16, n);
		if (result == -1)
			return (-1);
		length += result;
	}
	if (n == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[num % 16], 1) == -1)
			return (-1);
	}
	if (n == 'x')
	{
		if (write(1, &"0123456789abcdef"[num % 16], 1) == -1)
			return (-1);
	}
	return (length + 1);
}
