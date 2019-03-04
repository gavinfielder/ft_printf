/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:36:06 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/14 20:09:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const static char	g_base[] = "0123456789abcdef";

void				ft_print_hex(unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16);
		write(1, g_base + (n % 16), 1);
	}
	else
	{
		write(1, g_base + n, 1);
	}
}
