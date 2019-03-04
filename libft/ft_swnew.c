/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:10:00 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:15:30 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stringwriter	*ft_swnew(char *buff_location, size_t capacity)
{
	t_stringwriter	*sw;

	sw = (t_stringwriter *)malloc(sizeof(t_stringwriter));
	if (sw == NULL)
		return (NULL);
	sw->type = 'W';
	sw->buff = buff_location;
	sw->capacity = capacity;
	sw->len = 0;
	return (sw);
}
