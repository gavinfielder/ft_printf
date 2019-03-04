/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdwdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:12:58 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:14:58 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_fdwdel(t_fdwriter **fdw)
{
	if (fdw == NULL || *fdw == NULL)
		return ;
	free(*fdw);
	*fdw = NULL;
}
