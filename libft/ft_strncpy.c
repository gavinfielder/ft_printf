/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:27:04 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:36:49 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (i == j && src[i] != '\0')
		{
			dst[i] = src[i];
			j++;
		}
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
