/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_get_start_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:09:22 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 11:42:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hat_get_start_index(t_hat *hat, int index)
{
	if (index < 0)
	{
		index -= ((int)(hat->leaf_capacity) - 1);
		return (((index / (int)(hat->leaf_capacity))
					* (int)(hat->leaf_capacity)));
	}
	return ((index / hat->leaf_capacity) * hat->leaf_capacity);
}
