/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:44:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:37:15 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t max_len)
{
	size_t	len;
	size_t	match;
	size_t	i;

	match = 0;
	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return ((char *)str);
	while (str[i] != '\0' && match < len && i < max_len)
	{
		if (str[i] == to_find[match])
			match++;
		else
		{
			i = i - match;
			match = 0;
		}
		i++;
	}
	if (match == len)
		return ((char *)(str + i - match));
	else
		return (0);
}
