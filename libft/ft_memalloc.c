/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:57:11 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 09:14:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	if (size == 0)
		return (NULL);
	ret = malloc(size);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i < size)
	{
		*((unsigned char *)ret + i) = 0;
		i++;
	}
	return (ret);
}
