/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:54:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/15 18:30:31 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == MY_INT_MIN)
		{
			ft_putchar_fd('2', fd);
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('0' + (nb % 10), fd);
	}
	else
		ft_putchar_fd('0' + nb, fd);
}
