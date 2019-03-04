/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:25:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:25:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		value;
	size_t	i;

	value = 0;
	i = 0;
	while (value == 0 && i < n)
	{
		value += (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (value);
}
