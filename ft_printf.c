/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:15:25 by lteng             #+#    #+#             */
/*   Updated: 2023/09/21 13:15:27 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_in_set(char a, char *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_printf_input(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_function_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_printf_function_s(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_function_di(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printf_function_u(va_arg(args, unsigned int)));
	else if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (c == 'x')
		return (ft_printf_function_smallx(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printf_function_bigx(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_printf_function_p(va_arg(args, void *)));
	return (0);
}

static int	ft_vprintf(const char *format, va_list args)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%' && char_in_set(*(format + 1), "cspdiuxX%"))
		{
			res += ft_printf_input(*(format + 1), args);
			format += 2;
		}
		else
		{
			ft_putchar(*format);
			res++;
			format++;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vprintf(format, args);
	va_end(args);
	return (res);
}
