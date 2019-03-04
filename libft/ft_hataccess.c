/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hataccess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:05:04 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/19 19:59:36 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hataccess(t_hat *hat, int index)
{
	int		start_index;
	t_hatlf	*lf;
	t_hatlf	*current;

	if (hat == NULL)
		return (NULL);
	current = hat->head;
	start_index = ft_hat_get_start_index(hat, index);
	while (current && current->start_index < start_index)
		current = current->next;
	if (!current || current->start_index != start_index)
	{
		lf = ft_hatlfnew(hat->leaf_capacity, hat->atom_size, start_index);
		if (lf == NULL)
			return (NULL);
		ft_hatinslf(hat, lf);
		return (lf->data + ((index - start_index) * (hat->atom_size)));
	}
	return (current->data + ((index - start_index) * (hat->atom_size)));
}
