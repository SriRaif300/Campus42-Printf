/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:38:13 by cgaratej          #+#    #+#             */
/*   Updated: 2024/02/04 20:01:02 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_type(char c, va_list element)
{
	if (c == 'c')
		return (ft_putchar(va_arg(element, int)));
	if (c == 's')
		return (ft_putstr(va_arg(element, char *)));
	if (c == 'p')
		return (0);
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(element, int)));
	if (c == 'u')
		return (ft_putnbr_nosig(va_arg(element, unsigned int)));
	if (c == 'x')
		return (ft_puthex_min(va_arg(element, int), 'x'));
	if (c == 'X')
		return (ft_puthex_min(va_arg(element, int), 'X'));
	return (0);
}

static int	ft_ispercentage(char c, va_list element)
{
	int	len;

	if (c != '%')
	{
		len = ft_arg_type(c, element);
		if (len == -1)
			return (-1);
		return (len);
	}
	else
	{
		if (ft_putchar(c) == -1)
			return (-1);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len = ft_ispercentage(str[i + 1], args);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
