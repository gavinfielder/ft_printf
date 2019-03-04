/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_toarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:51:16 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/20 12:14:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	initial_error_checks(t_hat *hat, int index,
				t_hatlf **current, int *local)
{
	if (hat == NULL || hat->head == NULL)
		return (0);
	*current = hat->head;
	while ((int)((*current)->start_index + hat->leaf_capacity) - 1 < index)
		*current = (*current)->next;
	*local = index - (*current)->start_index;
	if (*local < 0 || *local >= (int)(hat->leaf_capacity))
		return (0);
	return (1);
}

static void	*abort_copy(void *arr)
{
	free(arr);
	return (NULL);
}

void		*ft_hat_toarr(t_hat *hat, int index, size_t count)
{
	void	*arr;
	t_hatlf	*current;
	int		i;
	int		local;

	if (count == 0)
		return (ft_strdup(""));
	if (initial_error_checks(hat, index, &current, &local) == 0 ||
			(!((arr = ft_memalloc((count * hat->atom_size) + 1)))))
		return (NULL);
	i = 0;
	while (count--)
	{
		ft_memcpy(arr + i++, current->data + local, hat->atom_size);
		index++;
		local++;
		if (local == (int)(hat->leaf_capacity))
		{
			current = current->next;
			local = 0;
			if ((!current && count) || index != current->start_index)
				return (abort_copy(arr));
		}
	}
	return (arr);
}
