/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/03 21:38:03 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	run_all_tests();
	/*
	char *str;
	int	ret_val;

	if (argc > 1)
	{
		ret_val = ft_asprintf(&str, argv[1]);
		printf("returned %i and \"%s\"\n", ret_val, str);
		free(str);
	}
	while (1);
	*/
	return (0);
}
