/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:43:41 by exam              #+#    #+#             */
/*   Updated: 2019/02/15 18:28:35 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

const static char	g_base[] = "0123456789abcdef";

static void	putc_np(unsigned char c)
{
	if (c >= 32 && c <= 126)
		write(1, (char *)(&c), 1);
	else
		write(1, ".", 1);
}

static void	print_hexbyte(const void *loc)
{
	if (*((unsigned char *)loc) < 16)
		write(1, "0", 1);
	else
		write(1, g_base + *((unsigned char *)loc) / 16, 1);
	write(1, g_base + *((unsigned char *)loc) % 16, 1);
}

static void	print_memline(const void *addr, size_t size)
{
	size_t	i;

	if (size >= 16)
		size = 16;
	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hexbyte(addr + i);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		putc_np(*((unsigned char *)(addr + i)));
		i++;
	}
	write(1, "\n", 1);
}

void		ft_print_memory(const void *addr, size_t size)
{
	while (size)
	{
		print_memline(addr, size);
		if (size > 16)
		{
			size -= 16;
			addr += 16;
		}
		else
			size = 0;
	}
}
