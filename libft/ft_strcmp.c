/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:33:12 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/11 15:43:18 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	value;
	int i;

	value = 0;
	i = 0;
	while (value == 0 && (s1[i] || s2[i]))
	{
		value += ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (value);
}
