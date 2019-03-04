/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_backend.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:54:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/02 21:08:23 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_BACKEND_H
# define FTPF_BACKEND_H

# include "libft.h"
# include <stdarg.h>

# define FTPF_SIZEMOD_HH   1
# define FTPF_SIZEMOD_H    2
# define FTPF_SIZEMOD_L    3
# define FTPF_SIZEMOD_LL   4
# define FTPF_SIZEMOD_BIGL 5

# define FTPF_NUM_CHECKFLAGS 25
# define FTPF_CHECKFLAG_INIT 0x01FEFFFF
# define FTPF_CHECKER_BEGIN 2
# define FTPF_CHECKER_END (FTPF_NUM_CHECKFLAGS - 1)

# define FTPF_FORMAT_ZEROPAD 0x04
# define FTPF_FORMAT_SPCEPAD 0x08
# define FTPF_FORMAT_ALTFORM 0x10
# define FTPF_FORMAT_NEGAPAD 0x20
# define FTPF_FORMAT_ALLSIGN 0x40

# define FTPF_NUM_EXPANDERS 11

# define FTPF_UNLIMITED_LEN -1

/*
** -----------------------------------------------------------------------------
**                        CHECK_FLAGS
** -----------------------------------------------------------------------------
**  bit        description                  masks      mask description
** -----------------------------------------------------------------------------
**   0   %%  : print a %                    0000.0000  (disallows all)
** -----------------------------------------------------------------------------
**   1   ##$ : choose argument number       FFFF.FFFC  (disallows self & prior)
** -----------------------------------------------------------------------------
**   2   0   : zero padding                 FFFF.FFF8  (self & prior groups)
**   3   ' ' : space before positive        FFFF.FFF4  (self & prior groups)
**   4   #   : alternate format display     FFFF.FFEC  (self & prior groups)
**   5   -   : pad for negative sign        FFFF.FFDC  (self & prior groups)
**   6   +   : always put a sign            FFFF.FFBC  (self & prior groups)
** -----------------------------------------------------------------------------
**   7   ##  : field width                  FFFF.FF00  (disallows self & prior)
** -----------------------------------------------------------------------------
**   8   .   : precision                    FFFF.FE00  (disallows self & prior)
** -----------------------------------------------------------------------------
**   9   hh  : short short size modifier    FFFF.C000  (prior & same group)
**   10  h   : short size modifer           FFFF.C000  (prior & same group)
**   11  ll  : long long size modifier      FFFF.C000  (prior & same group)
**   12  l   : long size modifier           FFFF.C000  (prior & same group)
**   13  L   : long double size modifier    FFFF.C000  (prior & same group)
** -----------------------------------------------------------------------------
**   14  p   : ptr expansion                0000.0000  (disallows all)
**   15  di  : signed integer expansion     0000.0000  (disallows all)
**   16        UNUSED                       0000.0000  (disallows all)
**   17  u   : unsigned integer expansion   0000.0000  (disallows all)
**   18  x   : hex expansion lower          0000.0000  (disallows all)
**   19  X   : hex expansion upper          0000.0000  (disallows all)
**   20  f   : float expansion              0000.0000  (disallows all)
**   21  s   : string expansion             0000.0000  (disallows all)
**   22  c   : char expansion               0000.0000  (disallows all)
**   23  o   : octal expansion              0000.0000  (disallows all)
**   24  m   : memory expansion             0000.0000  (disallows all)
** -----------------------------------------------------------------------------
**   25 - 31   UNUSED
** -----------------------------------------------------------------------------
*/

/*
** --------------------------------------------
**                 FORMAT_FLAGS
** --------------------------------------------
**  bit        description
** --------------------------------------------
**   0         UNUSED
**   1         UNUSED
**   2   0   : zero padding
**   3   ' ' : space before positive
**   4   #   : alternate format display
**   5   -   : pad for negative sign
**   6   +   : always put a sign
**   7         UNUSED
** --------------------------------------------
*/

typedef struct	s_ftpf_master_data		t_ftpf_master_data;
typedef struct	s_ftpf_expandler		t_ftpf_expandler;
typedef	int		(*t_ftpf_expander_func)	(t_ftpf_master_data *);
typedef int		(*t_ftpf_checker_func)	(t_ftpf_expandler *);

struct									s_ftpf_expandler
{
	const char							*start;
	void								*data;
	unsigned int						check_flags;
	unsigned char						handled_len;
	unsigned char						total_specifier_len;
	unsigned char						format_flags;
	unsigned char						field_width;
	unsigned char						precision;
	unsigned char						size_mod;
	va_list								args;
	unsigned char						arg_num;
	t_ftpf_expander_func				expand;
};

struct							s_ftpf_master_data
{
	int									i;
	int									max_len;
	int									len;
	va_list								args;
	t_ftpf_expandler					*ex;
	t_multistringer						*ms;
};

/*
** -----------------------------------------------------------------------------
**                             Primary Functions
** -----------------------------------------------------------------------------
*/

void									ftpf_expandler_init
										(t_ftpf_expandler *ex,
										const char *start, va_list args,
										unsigned char default_arg);
void									ftpf_read_specifier
										(t_ftpf_expandler *ex);
void									ftpf_get_arg(t_ftpf_expandler *ex);

int										ftpf_master(t_multistringer *ms,
										const char *fmt, int max_len,
										va_list args);

int										ft_vsbprintf(t_stringbuilder *sb,
										const char *fmt, va_list args);
int										ft_vdprintf(int fd, const char *fmt,
										va_list args);
int										ft_vsprintf(char *str, const char *fmt,
										va_list args);
int										ft_vsnprintf(char *str, size_t size,
										const char *fmt, va_list args);

/*
** -----------------------------------------------------------------------------
**                             Checker Functions
** -----------------------------------------------------------------------------
*/

extern const	t_ftpf_checker_func		g_checkfuncs[FTPF_NUM_CHECKFLAGS];

int										ftpf_check_percent
										(t_ftpf_expandler *expandler);
int										ftpf_get_arg_num
										(t_ftpf_expandler *expandler);
int										ftpf_check_zeropad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_spacepad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_alternate_form_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_negativepad_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_alwayssign_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_fieldwidth_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_precision_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_shortshort_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_short_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_long_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_longlong_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_longdouble_mod
										(t_ftpf_expandler *expandler);
int										ftpf_check_ptr_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_signed_int_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_unsigned_int_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_hexlower_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_hexupper_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_float_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_string_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_char_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_octal_expansion
										(t_ftpf_expandler *expandler);
int										ftpf_check_memory_expansion
										(t_ftpf_expandler *expandler);

/*
** -----------------------------------------------------------------------------
**                            Expander Functions
** -----------------------------------------------------------------------------
*/

extern const	t_ftpf_expander_func	g_expander_funcs[FTPF_NUM_EXPANDERS];

int										ftpf_percent_expander(
											t_ftpf_master_data *md);
int										ftpf_ptr_expander(
											t_ftpf_master_data *md);
int										ftpf_signed_int_expander(
											t_ftpf_master_data *md);
int										ftpf_unsigned_int_expander(
											t_ftpf_master_data *md);
int										ftpf_hexlower_expander(
											t_ftpf_master_data *md);
int										ftpf_hexupper_expander(
											t_ftpf_master_data *md);
int										ftpf_float_expander(
											t_ftpf_master_data *md);
int										ftpf_string_expander(
											t_ftpf_master_data *md);
int										ftpf_char_expander(
											t_ftpf_master_data *md);
int										ftpf_octal_expander(
											t_ftpf_master_data *md);
int										ftpf_memory_expander(
											t_ftpf_master_data *md);

#endif
