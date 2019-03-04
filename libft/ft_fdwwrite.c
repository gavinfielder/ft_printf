/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdwwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:14:21 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:14:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_fdwwrite(t_fdwriter *fdw, const char *str)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
	}
}
