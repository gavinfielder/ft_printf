/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_np.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:03:51 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/21 22:13:13 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_np(char c, char c_if_nonprintable)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, &c_if_nonprintable, 1);
}
