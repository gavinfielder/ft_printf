/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:01:30 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:33:45 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*r;
	unsigned int	i;
	size_t			len_s1;
	size_t			len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r = ft_strnew(len_s1 + len_s2);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		r[i] = s1[i];
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		r[i] = s2[i - len_s1];
		i++;
	}
	return (r);
}
