/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:57:34 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 09:45:47 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	len;
	int	match;
	int	i;

	match = 0;
	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return ((char *)str);
	while (str[i] != '\0' && match < len)
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
