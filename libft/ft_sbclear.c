/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:16:17 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:49:50 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sbclear(t_stringbuilder *sb)
{
	t_hatlf *tmp;

	while (sb->hat->head->next)
	{
		tmp = sb->hat->head->next;
		ft_hatdellf(sb->hat, &tmp);
	}
	ft_bzero(sb->hat->head->data, sb->hat->leaf_capacity);
	sb->len = 0;
}
