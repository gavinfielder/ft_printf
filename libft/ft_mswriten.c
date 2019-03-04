/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swsbwriten.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:39:30 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:20:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mswriten(t_multistringer *ms, const char *str, size_t n)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwriten((t_stringbuilder *)ms, str, n);
	else if (ms->sb.type == 'W')
		ft_swwriten((t_stringwriter *)ms, str, n);
	else
		ft_fdwwriten((t_fdwriter *)ms, str, n);
}
