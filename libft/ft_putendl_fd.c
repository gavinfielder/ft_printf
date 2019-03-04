/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:53:23 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:29:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
