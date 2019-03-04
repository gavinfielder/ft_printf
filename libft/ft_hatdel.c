/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:35:46 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 19:06:36 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_hatdel(t_hat **hat)
{
	t_hatlf	*tmp;

	while ((*hat)->head)
	{
		tmp = (*hat)->head;
		ft_hatdellf(*hat, &tmp);
	}
	free(*hat);
	*hat = NULL;
}
