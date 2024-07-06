/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:53:33 by lteng             #+#    #+#             */
/*   Updated: 2023/09/23 09:52:18 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (*c)
	{
		c++;
		count++;
	}
	return (count);
}

int	ft_printf_function_smallx(unsigned int input)
{
	const char			*base;
	int					count;
	unsigned long		length;
	unsigned long		temp;

	temp = (unsigned long)input;
	base = "0123456789abcdef";
	count = 0;
	length = ft_strlen(base);
	if (temp > (length - 1))
	{
		count += ft_printf_function_smallx(temp / length);
		count += ft_printf_function_smallx(temp % length);
	}
	else if (temp <= (length - 1))
	{
		ft_putchar(base[temp]);
		count++;
	}
	return (count);
}

int	ft_printf_function_bigx(unsigned int input)
{
	const char			*base;
	int					count;
	unsigned long		length;
	unsigned long		temp;

	temp = (unsigned long)input;
	base = "0123456789ABCDEF";
	count = 0;
	length = ft_strlen(base);
	if (temp > (length - 1))
	{
		count += ft_printf_function_bigx(temp / length);
		count += ft_printf_function_bigx(temp % length);
	}
	else if (temp <= (length - 1))
	{
		ft_putchar(base[temp]);
		count++;
	}
	return (count);
}

int	ft_printf_address(void *input)
{
	const char			*base;
	int					count;
	unsigned long		length;
	unsigned long		temp;

	temp = (unsigned long)input;
	base = "0123456789abcdef";
	length = ft_strlen(base);
	count = 0;
	if (temp > (length - 1))
	{
		count += ft_printf_address((void *)(temp / length));
		count += ft_printf_address((void *)(temp % length));
	}
	else if (temp <= (length - 1))
	{
		ft_putchar(base[temp]);
		count++;
	}
	return (count);
}

int	ft_printf_function_p(void *input)
{
	int	count;

	if (input == 0)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	else
	{
		ft_putchar('0');
		ft_putchar('x');
		count = 2 + ft_printf_address(input);
		return (count);
	}
}
