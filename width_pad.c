/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:59:48 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/21 18:31:42 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_printf_width_pad(int len, int width, char padwidth)
{
	while (len < width)
	{
		ft_putchar(padwidth);
		len++;
	}
}
