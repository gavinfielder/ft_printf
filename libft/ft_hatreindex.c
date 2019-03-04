/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatreindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:31:52 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 21:49:55 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hatreindex(t_hat *hat, int head_index)
{
	int		prev_old_index;
	int		prev_new_index;
	int		difference;
	t_hatlf	*current;

	if (hat == NULL || hat->head == NULL)
		return (0);
	current = hat->head;
	prev_old_index = current->start_index;
	current->start_index = head_index;
	prev_new_index = head_index;
	difference = prev_new_index - prev_old_index;
	current = current->next;
	while (current)
	{
		current->start_index += difference;
		current = current->next;
	}
	return (difference);
}
