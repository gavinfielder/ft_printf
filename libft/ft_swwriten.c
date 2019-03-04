/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swwriten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:29:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:18:22 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swwriten(t_stringwriter *sw, const char *str, size_t n)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		if (sw->len >= sw->capacity - 1)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
		n--;
	}
	sw->buff[sw->len] = '\0';
}
