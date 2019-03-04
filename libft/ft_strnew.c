/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:17:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 17:24:26 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
