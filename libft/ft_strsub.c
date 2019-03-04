/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:56:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:40:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	r = ft_strnew(len);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	return (r);
}
