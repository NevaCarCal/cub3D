/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:02:37 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 18:02:40 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_nb(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_un(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), word);
	else if (word == '%')
	{
		size += 1;
		write(1, "%", 1);
	}
	else
		size += ft_print_character(word);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
			size += ft_print_character(str[i]);
		i++;
	}
	va_end(argument);
	return (size);
}
