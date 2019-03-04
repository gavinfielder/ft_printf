/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swwrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:21:00 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:17:29 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swwrite(t_stringwriter *sw, const char *str)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str)
	{
		if (sw->len >= sw->capacity - 1)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
	}
	sw->buff[sw->len] = '\0';
}
