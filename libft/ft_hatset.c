/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:03:41 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 15:05:27 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hatset(t_hat *hat, int index, void *data)
{
	void	*ptr;

	ptr = ft_hataccess(hat, index);
	if (ptr == NULL)
		return ;
	ft_memcpy(ptr, data, hat->atom_size);
}
