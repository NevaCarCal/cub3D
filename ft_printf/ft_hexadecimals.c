/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:02:08 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 18:02:13 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_hexadecimal(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_hexadecimal(num / 16, word);
		ft_hexadecimal(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_character(num + '0');
		else
		{
			if (word == 'x')
				ft_print_character(num - 10 + 'a');
			if (word == 'X')
				ft_print_character(num - 10 + 'A');
		}
	}
}

int	ft_print_hexadecimal(unsigned int num, const char word)
{
	if (num == 0)
		return (ft_print_character('0'));
	else
		ft_hexadecimal(num, word);
	return (ft_length_hexadecimal(num));
}
