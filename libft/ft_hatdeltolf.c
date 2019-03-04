/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatdeltolf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:54:49 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/20 11:02:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hatdeltolf(t_hat *hat, t_hatlf *lf)
{
	t_hatlf	*tmp;

	while (lf->prev)
	{
		tmp = lf->prev;
		ft_hatdellf(hat, &tmp);
	}
	while (lf->next)
	{
		tmp = lf->next;
		ft_hatdellf(hat, &tmp);
	}
}
