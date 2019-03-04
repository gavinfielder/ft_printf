/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:31:23 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/01 23:35:35 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swclear(t_stringwriter *sw)
{
	if (sw == NULL)
		return ;
	sw->len = 0;
	if (sw->buff == NULL)
		return ;
	ft_bzero(sw->buff, sw->capacity);
}
