/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:15 by acatusse          #+#    #+#             */
/*   Updated: 2023/02/16 17:19:10 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_formats(va_list args, const char format);
int ft_printf(const char *str, ...);

int	print_single_char(int c);
int	print_multiple_chars(char *str);
int	print_pointer(unsigned long pointer);
int	print_numbers(long nb);

int	print_unsigned_numbers(unsigned int nb);
int	print_hexa_min(unsigned long nb);
int	print_hexa_maj(unsigned long nb);
int	print_percent();

#	endif