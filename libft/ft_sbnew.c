/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:53:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 04:11:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stringbuilder	*ft_sbnew(void)
{
	t_stringbuilder	*sb;

	sb = (t_stringbuilder *)malloc(sizeof(t_stringbuilder));
	if (sb == NULL)
		return (NULL);
	sb->hat = ft_hatnew(FT_STRINGBUILDER_LEAFSIZE, 1);
	sb->len = 0;
	sb->type = 'B';
	return (sb);
}
