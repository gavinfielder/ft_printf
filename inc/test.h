/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:10:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/03 21:43:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include "ftpf_backend.h"

# define TEST_OUTPUT_FILENAME "test_results.txt"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int		test(const char *fmt, ...);
void	print_format_flags(t_ftpf_expandler *ex);
void	print_expandler(t_ftpf_expandler *ex);
void	print_check_flags(t_ftpf_expandler *ex);

typedef	int	(* t_unit_test) (void);
extern const t_unit_test	g_unit_tests[];
void	run_all_tests(void);

#endif
