/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:25:09 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 11:57:27 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hat	*ft_hatnew(size_t leaf_capacity, size_t atom_size)
{
	t_hat	*hat;

	hat = (t_hat *)malloc(sizeof(t_hat));
	if (hat == NULL)
		return (NULL);
	hat->leaf_capacity = leaf_capacity;
	hat->atom_size = atom_size;
	hat->head = NULL;
	hat->tail = NULL;
	return (hat);
}
