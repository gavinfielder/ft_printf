/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbwrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:07:11 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:47:53 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sbwrite(t_stringbuilder *sb, const char *str)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)sb->len);
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
	}
}
