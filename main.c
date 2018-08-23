/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:54:07 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 13:31:01 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		main()
{
	ft_printf("% %\n");
	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
   	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeroes %010d \n", 1977);
	printf("***********************************************\n");
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d\n", 1977);
   	printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   ft_printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
	return (0);
}
