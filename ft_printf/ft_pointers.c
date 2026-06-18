/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:02:24 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 18:02:25 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_pointer(ptr / 16);
		ft_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_character(ptr + '0');
		else
			ft_print_character(ptr - 10 + 'a');
	}
}

static int	ft_length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
	{
		size += 5;
		write(1, "(nil)", 5);
	}
	else
	{
		size += ft_print_string("0x");
		ft_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}
