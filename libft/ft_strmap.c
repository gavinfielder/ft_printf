/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:34:05 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:34:31 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	r = ft_strnew(ft_strlen(s));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = f(s[i]);
		i++;
	}
	return (r);
}
