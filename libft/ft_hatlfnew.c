/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatlfnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 09:44:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 20:01:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hatlf		*ft_hatlfnew(size_t leaf_capacity, size_t atom_size,
				int start_index)
{
	t_hatlf	*lf;

	lf = (t_hatlf *)malloc(sizeof(t_hatlf));
	if (lf == NULL)
		return (NULL);
	lf->data = malloc(leaf_capacity * atom_size);
	if (lf->data == NULL)
	{
		free(lf);
		return (NULL);
	}
	ft_bzero(lf->data, leaf_capacity * atom_size);
	lf->next = NULL;
	lf->prev = NULL;
	lf->start_index = start_index;
	return (lf);
}
