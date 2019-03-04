/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:54:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:37:05 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int		value;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	value = 0;
	i = 0;
	while (value == 0 && i < n && (s1[i] || s2[i]))
	{
		value += ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (value)
		return (0);
	else
		return (1);
}
