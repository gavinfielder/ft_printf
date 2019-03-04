/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:46:59 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:35:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	r = ft_strnew(ft_strlen(s));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	return (r);
}
