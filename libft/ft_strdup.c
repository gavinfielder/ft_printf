/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:38:19 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/11 19:43:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		r[i] = str[i];
		i++;
	}
	return (r);
}
