/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:54:07 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 17:47:01 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		main()
{
	ft_printf(" %s \n", "This is a string");
	ft_printf("Characters %c %c\n", 'a', 65);
	ft_printf("Decimals %d %d\n", 1987, 123000);
	ft_printf("%i\n", 123456789);

	return (0);
}
