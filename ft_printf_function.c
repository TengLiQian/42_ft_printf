/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:53:28 by lteng             #+#    #+#             */
/*   Updated: 2023/09/23 09:52:00 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf_function_c(int input)
{
	ft_putchar(input);
	return (1);
}

int	ft_printf_function_s(char *input)
{
	int	count;

	count = 0;
	if (input == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
		return (count);
	}
	else
	{
		while (*input)
		{
			ft_putchar(*input);
			input++;
			count++;
		}
		return (count);
	}
}

int	ft_printf_function_di(int input)
{
	long	a;
	int		count;

	a = (long)input;
	count = 0;
	if (a < 0)
	{
		ft_putchar('-');
		count++;
		a = -a;
	}
	if (a > 9)
	{
		count += ft_printf_function_di(a / 10);
		count += ft_printf_function_di(a % 10);
	}
	if (a <= 9)
	{
		ft_putchar(a + '0');
		count++;
	}
	return (count);
}

int	ft_printf_function_u(unsigned int input)
{
	unsigned long	a;
	int				count;

	a = (unsigned long)input;
	count = 0;
	if (a > 9)
	{
		count += ft_printf_function_u(a / 10);
		count += ft_printf_function_u(a % 10);
	}
	if (a <= 9)
	{
		ft_putchar(a + '0');
		count++;
	}
	return (count);
}
