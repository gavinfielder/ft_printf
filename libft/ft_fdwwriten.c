/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdwwriten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:16:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:14:38 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_fdwwriten(t_fdwriter *fdw, const char *str, size_t n)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
		n--;
	}
}
