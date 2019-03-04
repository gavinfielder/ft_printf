/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdwnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:07:37 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:15:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_fdwriter	*ft_fdwnew(int fd)
{
	t_fdwriter	*fdw;

	fdw = (t_fdwriter *)malloc(sizeof(t_fdwriter));
	if (fdw == NULL)
		return (NULL);
	fdw->type = 'F';
	fdw->len = 0;
	fdw->fd = fd;
	return (fdw);
}
