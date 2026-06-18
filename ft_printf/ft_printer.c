/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:16 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 18:01:59 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
		return (ft_print_string("(null)"));
	while (str[size])
		size += ft_print_character(str[size]);
	return (size);
}

int	ft_print_nb(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_character('0');
	if (n == -2147483648)
	{
		size += ft_print_string("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_character('-');
		n = -n;
	}
	if (n > 0)
		size += ft_print_un((unsigned int)n);
	return (size);
}

int	ft_print_un(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_character('0');
	else
	{
		if (n / 10 != 0)
			ft_print_un(n / 10);
		ft_print_character((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_print_character(int character)
{
	write(1, &character, 1);
	return (1);
}
