/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:27:34 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:20:21 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_msdel(t_multistringer **ms)
{
	if (ms == NULL || *ms == NULL)
		return ;
	if ((*ms)->sb.type == 'B')
		ft_sbdel((t_stringbuilder **)ms);
	else if ((*ms)->sb.type == 'W')
		ft_swdel((t_stringwriter **)ms);
	else
		ft_fdwdel((t_fdwriter **)ms);
}
