/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:28:18 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 16:37:11 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy_elem(t_list *tocopy)
{
	t_list	*ret;

	ret = ft_lstnew(tocopy->content, tocopy->content_size);
	return (ret);
}
