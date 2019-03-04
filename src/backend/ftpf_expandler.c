/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_expandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:53:17 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:28:32 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"
#include <stdarg.h>

void	ftpf_expandler_init(t_ftpf_expandler *ex,
			const char *start, va_list args,
			unsigned char default_arg)
{
	ex->start = start;
	ex->data = NULL;
	ex->check_flags = FTPF_CHECKFLAG_INIT;
	ex->handled_len = 1;
	ex->total_specifier_len = 1;
	ex->format_flags = 0;
	ex->field_width = 0;
	ex->precision = 0;
	ex->size_mod = 0;
	ex->expand = NULL;
	ex->arg_num = default_arg;
	va_copy(ex->args, args);
}

void	ftpf_read_specifier(t_ftpf_expandler *ex)
{
	int			i;

	i = 0;
	while (ex->check_flags)
	{
		if (ex->check_flags & (1 << i))
		{
			if (g_checkfuncs[i](ex))
				i = 0;
		}
		i++;
	}
	ex->total_specifier_len = ex->handled_len;
}

/*
void	ftpf_get_arg(t_ftpf_expandler *ex)
{
	va_list			args;
	int				i;
	unsigned char	buff[32];

	va_copy(args, ex->args);
	i = 0;
	while (i < ex->arg_num)
		va_arg(args, ???type
*/
