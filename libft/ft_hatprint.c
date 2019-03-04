/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:02:17 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 22:13:50 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

static void	print_leaf_data(const t_hat *hat, t_hatlf *lf,
		int data_display_format)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < hat->leaf_capacity)
	{
		j = 0;
		while (j < hat->atom_size)
		{
			if (data_display_format == FT_HAT_PRINTMODE_HEX)
				ft_printhexbyte(lf->data + hat->atom_size * i + j);
			else if (data_display_format == FT_HAT_PRINTMODE_ASC)
				ft_putchar_np(*((char *)(lf->data + hat->atom_size * i + j)),
						'@');
			j++;
		}
		if (i != hat->leaf_capacity - 1)
			write(1, ".", 1);
		i++;
	}
}

static void	print_leaf(const t_hat *hat, t_hatlf *lf, int data_display_format)
{
	write(1, "  index ", 8);
	ft_putnbr(lf->start_index);
	write(1, "\t[", 2);
	print_leaf_data(hat, lf, data_display_format);
	write(1, "]\n", 2);
}

void		ft_hatprint(t_hat *hat, int data_display_format)
{
	t_hatlf	*current;

	if (hat == NULL)
	{
		write(1, "(NULL)\n", 7);
		return ;
	}
	if (hat->head == NULL)
	{
		write(1, "(empty hat)\n", 12);
		return ;
	}
	current = hat->head;
	while (current)
	{
		print_leaf(hat, current, data_display_format);
		current = current->next;
	}
}
