/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:49:14 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:32:33 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	int	value;
	int i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	value = 0;
	i = 0;
	while (value == 0 && (s1[i] || s2[i]))
	{
		value += ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (value)
		return (0);
	else
		return (1);
}
