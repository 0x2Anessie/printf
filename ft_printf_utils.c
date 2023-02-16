/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:03 by acatusse          #+#    #+#             */
/*   Updated: 2023/02/16 17:15:28 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_single_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_multiple_chars(char *str)
{
	int printable;

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		write(1, str, 1);
		printable++;
		str++;
	}
	return (printable);
}

int	print_pointer(unsigned long	pointer)
{
	int	printables;

	printables = 0;
	if (!pointer)
		return (write(1, "(nil)", 5));
	printables += write(1, "0x", 2);
	printables += print_hexa_min(pointer);
	return (printables);
}

int	print_numbers(long nb)
{
	int	printables;

	printables = 0;
	if (nb < 0)
	{
		nb *= -1;
		printables += write(1, "-", 1);
	}
	if (nb > 9)
	{
		printables += print_numbers(nb / 10);
		printables += print_numbers(nb % 10);
	}
	else
		printables += print_single_char(nb + '0');
	return (printables);
}