/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbwriten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:32 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:48:52 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sbwriten(t_stringbuilder *sb, const char *str, size_t n)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str && n)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)(sb->len));
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
		n--;
	}
}
