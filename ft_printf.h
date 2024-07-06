/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:02:11 by lteng             #+#    #+#             */
/*   Updated: 2023/09/21 13:02:12 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_printf_function_c(int input);
int		ft_printf_function_s(char *input);
int		ft_printf_function_di(int input);
int		ft_printf_function_u(unsigned int input);
int		ft_printf_function_smallx(unsigned int input);
int		ft_printf_function_bigx(unsigned int input);
int		ft_printf_address(void *input);
int		ft_printf_function_p(void *input);

#endif
