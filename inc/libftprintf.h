/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:49:47 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 19:54:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_sprintf(char *str, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);
int		ft_sbprintf(t_stringbuilder *sb, const char *fmt, ...);
int		ft_snprintf(char *str, size_t size, const char *fmt, ...);

#endif
