/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexbyte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:07:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 21:45:34 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const static char	g_base[] = "0123456789ABCDEF";

void				ft_printhexbyte(const void *loc)
{
	if (*((unsigned char *)loc) < 16)
		write(1, "0", 1);
	else
		write(1, g_base + (*((unsigned char *)loc) / 16), 1);
	write(1, g_base + (*((unsigned char *)loc) % 16), 1);
}
