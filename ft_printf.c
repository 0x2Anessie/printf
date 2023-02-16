/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:10 by acatusse          #+#    #+#             */
/*   Updated: 2023/02/16 17:19:01 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	printables;

	printables = 0;
	// va_arg retourne une copie de l'argument suivant dans la liste, en le 
	// convertissant au type spécifié
	if (format == 'c')
		printables += print_single_char(va_arg(args, int));
	else if (format == 's')
		printables += print_multiple_chars(va_arg(args, char *));
	else if (format == 'p')
		printables += print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		printables += print_numbers(va_arg(args, long));
	else if (format == 'u')
		printables += print_unsigned_numbers(va_arg(args, unsigned int));
	else if (format == 'x')
		printables += print_hexa_min(va_arg(args, unsigned long));
	else if (format == 'X')
		printables += print_hexa_maj(va_arg(args, unsigned long));
	else if (format == '%')
		printables += print_percent();
	return (printables);
}

int ft_printf(const char *str, ...)
{
	int	i;
	va_list args;
	int	printables;

	i = 0;
	printables = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printables += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printables);
}

int	main()
{
	// char
	char c = 'N';
	ft_printf("ft_printf : ceci est un char %c\n", c);
	printf("printf : ceci est un char %c\n\n", c);
	
	// string
	char *str = "lolilol";
	ft_printf("ft_printf : ceci est une string %s\n", str);
	printf("printf : ceci est une string %s\n\n", str);

	// pointer adress
	char *string = "hihi";
	void *ptr = string;
	ft_printf("ft_printf : ceci est un pointeur %p\n", ptr);
	printf("printf : ceci est un pointeur %p\n\n", ptr);

	// nombre décimal
	int nb = 42.4;
	ft_printf("ft_printf : ceci est un nombre décimal %d\n", nb);
	printf("printf : ceci est un nombre décimal %d\n\n", nb);

	// entier en base 10
	int entier = 4242;
	ft_printf("ft_printf : ceci est un entier en base 10 %i\n", entier);
	printf("printf : ceci est un entier en base 10 %i\n\n", entier);

	// nombre décimal non signé
	int unsignd = 42;
	ft_printf("ft_printf : ceci est un nombre décimal non signé %u\n", unsignd);
	printf("printf : ceci est un nombre décimal non signé %u\n\n", unsignd);

	// nombre hexadécimal avec des lettres minuscules
	unsigned int hexamin = 0x25ab7;
	ft_printf("ft_printf : ceci est un nombre hexadécimal avec des lettres minuscules %x\n", hexamin);
	printf("printf : ceci est un nombre hexadécimal avec des lettres minuscules %x\n\n", hexamin);

	// nombre hexadécimal avec des lettres majuscules
	unsigned int hexamaj = 0x25AB4;
	ft_printf("ft_printf : ceci est un nombre hexadécimal avec des lettres majuscules %X\n", hexamaj);
	printf("printf : ceci est un nombre hexadécimal avec des lettres majuscules %X\n\n", hexamaj);

	// signe pourcentage
	ft_printf("ft_printf : ceci est un signe pourcentage %%\n");
	printf("printf : ceci est un signe pourcentage %%\n\n");
}