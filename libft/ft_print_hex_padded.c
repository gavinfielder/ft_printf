/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_padded.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:37:41 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/14 20:07:24 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const static char	g_base[] = "0123456789abcdef";

static void			print_hex_padded_rec(unsigned int n, unsigned int width,
		unsigned int digit)
{
	if (n >= 16 || digit < width - 1)
	{
		print_hex_padded_rec(n / 16, width, digit + 1);
		write(1, g_base + (n % 16), 1);
	}
	else
	{
		write(1, g_base + n, 1);
	}
}

void				ft_print_hex_padded(unsigned int n, unsigned int width)
{
	print_hex_padded_rec(n, width, 0);
}
