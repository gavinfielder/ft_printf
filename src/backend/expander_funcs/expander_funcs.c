/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:08:07 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 20:53:42 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"
#include "libft.h"

const	t_ftpf_expander_func	g_expander_funcs[FTPF_NUM_EXPANDERS] =
{
	ftpf_percent_expander, 		//0
	ftpf_ptr_expander, 			//1
	ftpf_signed_int_expander, 	//2
	ftpf_unsigned_int_expander, //3
	ftpf_hexlower_expander,		//4
	ftpf_hexupper_expander,		//5
	ftpf_float_expander,		//6
	ftpf_string_expander,		//7
	ftpf_char_expander,			//8
	ftpf_octal_expander,		//9
	ftpf_memory_expander		//10
};

int								ftpf_percent_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[PCT]");
	return (5);
}

int								ftpf_ptr_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[PTR]");
	return (5);
}

int								ftpf_signed_int_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[SINT]");
	return (6);
}

int								ftpf_unsigned_int_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[UINT]");
	return (6);
}

int								ftpf_hexlower_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[HEXL]");
	return (6);
}

int								ftpf_hexupper_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[HEXU]");
	return (6);
}

int								ftpf_float_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[FLOAT]");
	return (7);
}

int								ftpf_string_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[STR]");
	return (5);
}

int								ftpf_char_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[CHAR]");
	return (6);
}

int								ftpf_octal_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[OCT]");
	return (5);
}

int								ftpf_memory_expander(
									t_ftpf_master_data *md)
{
	ft_mswrite(md->ms, "[MEM]");
	return (5);
}
