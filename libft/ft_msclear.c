/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swsbclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:40:09 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:21:11 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_msclear(t_multistringer *ms)
{
	if (ms == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbclear((t_stringbuilder *)ms);
	else if (ms->sb.type == 'W')
		ft_swclear((t_stringwriter *)ms);
	else
		ft_fdwclear((t_fdwriter *)ms);
}
