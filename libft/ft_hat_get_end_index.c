/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_get_end_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:14:27 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 11:32:07 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hat_get_end_index(t_hat *hat, int index)
{
	return (ft_hat_get_start_index(hat, index) + hat->leaf_capacity - 1);
}
