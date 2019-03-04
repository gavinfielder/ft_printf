/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:30:36 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:22:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftpf_backend.h"
#include <stdarg.h>

static int			ftpf_master_helper(const char *fmt, t_ftpf_master_data *md)
{
	while (fmt[md->i])
	{
		if (fmt[md->i] == '%')
		{
			ftpf_expandler_init(md->ex, fmt + md->i, md->args, 
					md->ex->arg_num + 1);
			ftpf_read_specifier(md->ex);
			if (md->ex->expand)
			{
				(md->len) += md->ex->expand(md);
				(md->i) += md->ex->total_specifier_len;
			}
		}
		else
		{
			if (md->max_len < 0 || md->len < md->max_len)
				ft_mswriten(md->ms, fmt + md->i, 1);
			(md->len)++;
			(md->i)++;
		}
	}
	return (md->len);
}

int				ftpf_master(t_multistringer *ms, const char *fmt, int max_len,
					va_list args)
{
	t_ftpf_master_data	md;
	t_ftpf_expandler	ex;

	ex.arg_num = 0;
	md.ms = ms;
	md.len = 0;
	md.i = 0;
	md.max_len = max_len;
	va_copy(md.args, args);
	md.ex = &ex;
	return (ftpf_master_helper(fmt, &md));
}
