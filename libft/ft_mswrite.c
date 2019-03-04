/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swsbwrite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:37:54 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:20:39 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mswrite(t_multistringer *ms, const char *str)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwrite((t_stringbuilder *)ms, str);
	else if (ms->sb.type == 'W')
		ft_swwrite((t_stringwriter *)ms, str);
	else
		ft_fdwwrite((t_fdwriter *)ms, str);
}
