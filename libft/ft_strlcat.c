/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:15:54 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:34:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_initial_size;
	size_t j;
	size_t src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	dest_initial_size = 0;
	while (dest[dest_initial_size] != '\0')
		dest_initial_size++;
	if (dest_initial_size < size)
	{
		j = 0;
		while (dest_initial_size + j < size - 1 && j < src_size)
		{
			dest[dest_initial_size + j] = src[j];
			j++;
		}
		dest[dest_initial_size + j] = '\0';
	}
	if (size < dest_initial_size)
		return (size + src_size);
	else
		return (dest_initial_size + src_size);
}
