/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:32:54 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:21:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"
#include <stdio.h> //debug

const	t_ftpf_checker_func		g_checkfuncs[FTPF_NUM_CHECKFLAGS] =
{
	ftpf_check_percent,
	ftpf_get_arg_num,
	ftpf_check_zeropad_mod,
	ftpf_check_spacepad_mod,
	ftpf_check_alternate_form_mod,
	ftpf_check_negativepad_mod,
	ftpf_check_alwayssign_mod,
	ftpf_check_fieldwidth_mod,
	ftpf_check_precision_mod,
	ftpf_check_shortshort_mod,
	ftpf_check_short_mod,
	ftpf_check_longlong_mod,
	ftpf_check_long_mod,
	ftpf_check_longdouble_mod,
	ftpf_check_ptr_expansion,
	ftpf_check_signed_int_expansion,
	NULL,
	ftpf_check_unsigned_int_expansion,
	ftpf_check_hexlower_expansion,
	ftpf_check_hexupper_expansion,
	ftpf_check_float_expansion,
	ftpf_check_string_expansion,
	ftpf_check_char_expansion,
	ftpf_check_octal_expansion,
	ftpf_check_memory_expansion
};

static int						number_len(t_ftpf_expandler *ex)
{
	int		i;
	char	c;

	i = 0;
	c = *(ex->start + ex->handled_len + i);
	while (1)
	{
		if (!(c >= '0' && c <= '9'))
			return (i);
		i++;
		c = *(ex->start + ex->handled_len + i);
	}
	return (0);
}

/*
** -----------------------------------------------------------------------------
**                             Checker Functions
** -----------------------------------------------------------------------------
*/

int								ftpf_check_percent
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '%')
	{
		ex->check_flags &= 0x00000000;
		ex->handled_len++;
		ex->expand = ftpf_percent_expander;
		return (1);
	}
	ex->check_flags &= 0xFFFFFFFE;
	return (0);
}

int								ftpf_get_arg_num
									(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		if (*(ex->start + ex->handled_len + len) == '$')
		{

			ex->arg_num = (unsigned char)ft_atoi(ex->start + ex->handled_len);
			ex->handled_len += len;
			ex->check_flags &= 0xFFFFFFFC;
			return (1);
		}
	}
	ex->check_flags &= ~(1 << 1);
	return (0);
}

int								ftpf_check_zeropad_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '0')
	{
		ex->check_flags &= 0xFFFFFFFF;
		ex->handled_len++;
		ex->format_flags |= FTPF_FORMAT_ZEROPAD;
		return (1);
	}

	return (0);
}

int								ftpf_check_spacepad_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == ' ')
	{
		ex->check_flags &= 0xFFFFFFFF;
		ex->handled_len++;
		ex->format_flags |= FTPF_FORMAT_SPCEPAD;
		return (1);
	}
	return (0);
}

int								ftpf_check_alternate_form_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '#')
	{
		ex->check_flags &= 0xFFFFFFFF;
		ex->handled_len++;
		ex->format_flags |= FTPF_FORMAT_ALTFORM;
		return (1);
	}
	return (0);
}

int								ftpf_check_negativepad_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '-')
	{
		ex->check_flags &= 0xFFFFFFFF;
		ex->handled_len++;
		ex->format_flags |= FTPF_FORMAT_NEGAPAD;
		return (1);
	}
	return (0);
}

int								ftpf_check_alwayssign_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '+')
	{
		ex->check_flags &= 0xFFFFFFFF;
		ex->handled_len++;
		ex->format_flags |= FTPF_FORMAT_ALLSIGN;
		return (1);
	}
	return (0);
}

int								ftpf_check_fieldwidth_mod
									(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		ex->field_width = (unsigned char)ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFFF00;
		return (1);
	}
	ex->check_flags &= ~(1 << 7);
	return (0);
}

int								ftpf_check_precision_mod
									(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) == '.')
	{
		ex->handled_len++;
		len = number_len(ex);
		ex->precision = (unsigned char)ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFFE00;
		return (1);
	}
	ex->check_flags &= ~(1 << 8);
	return (0);
}

int								ftpf_check_shortshort_mod
									(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'h') &&
		*(ex->start + ex->handled_len + 1) == 'h')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_HH;
		ex->check_flags &= 0xFFFFC000;
		return (1);
	}
	ex->check_flags &= ~(1 << 9);
	return (0);
}

int								ftpf_check_short_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'h')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_H;
		ex->check_flags &= 0xFFFFC000;
		return (1);
	}
	ex->check_flags &= ~(1 << 10);
	return (0);
}

int								ftpf_check_longlong_mod
									(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'l') &&
		*(ex->start + ex->handled_len + 1) == 'l')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_LL;
		ex->check_flags &= 0xFFFFC000;
		return (1);
	}
	ex->check_flags &= ~(1 << 11);
	return (0);
}


int								ftpf_check_long_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'l')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_L;
		ex->check_flags &= 0xFFFFC000;
		return (1);
	}
	ex->check_flags &= ~(1 << 12);
	return (0);
}

int								ftpf_check_longdouble_mod
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'L')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_BIGL;
		ex->check_flags &= 0xFFFFC000;
		return (1);
	}
	ex->check_flags &= ~(1 << 13);
	return (0);
}

int								ftpf_check_ptr_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'p')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_ptr_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 14);
	return (0);
}

int								ftpf_check_signed_int_expansion
									(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'd') || 
		(*(ex->start + ex->handled_len) == 'i'))
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_signed_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 15);
	return (0);
}

int								ftpf_check_unsigned_int_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'u')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_unsigned_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 17);
	return (0);
}

int								ftpf_check_hexlower_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'x')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexlower_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 18);
	return (0);
}

int								ftpf_check_hexupper_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'X')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexupper_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 19);
	return (0);
}

int								ftpf_check_float_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'f')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_float_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 20);
	return (0);
}

int								ftpf_check_string_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 's')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_string_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 21);
	return (0);
}

int								ftpf_check_char_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'c')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_char_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 22);
	return (0);
}

int								ftpf_check_octal_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'o')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_octal_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 23);
	return (0);
}

int								ftpf_check_memory_expansion
									(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'm')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_memory_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 24);
	return (0);
}
