/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:03:54 by exam              #+#    #+#             */
/*   Updated: 2019/02/15 18:51:08 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const static char	g_base[] = "0123456789ABCDEF";

static char	*format_return(char *buff, int len)
{
	int		i;
	char	*ret;

	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = buff[len - i - 1];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

char		*ft_itoa_base(int value, int base)
{
	int		negative;
	char	buff[33];
	int		len;

	negative = 0;
	if ((base == 10) && value < 0)
		negative = 1;
	len = 0;
	while (value || len == 0)
	{
		buff[len] = g_base[ABS(value % base)];
		len++;
		value /= base;
	}
	if (negative)
	{
		buff[len] = '-';
		len++;
	}
	return (format_return(buff, len));
}
