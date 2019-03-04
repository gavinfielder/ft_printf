/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_byref.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:24:49 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 14:51:22 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew_byref(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = (void *)content;
	}
	lst->next = NULL;
	return (lst);
}
