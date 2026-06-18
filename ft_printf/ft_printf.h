/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:02:48 by brimarti          #+#    #+#             */
/*   Updated: 2024/11/06 18:02:52 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_character(int character);
int	ft_printf(const char *str, ...);
int	ft_print_string(char *str);
int	ft_print_nb(int n);
int	ft_print_un(unsigned int n);
int	ft_print_hexadecimal(unsigned int num, const char word);
int	ft_print_pointer(unsigned long long ptr);

#endif
