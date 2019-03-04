/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:01:44 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:51:46 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_sbdel(t_stringbuilder **sb)
{
	if (sb == NULL || *sb == NULL)
		return ;
	ft_hatdel(&(((*sb)->hat)));
	free(*sb);
	*sb = NULL;
}
