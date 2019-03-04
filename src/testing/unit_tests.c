/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/03 22:09:53 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** Add unit tests to this file. Return 1 if fail, 0 if pass.
**
** All functions of the prototype:
**
**     int    foo(void)
**
** will be considered a unit test.
*/

int		no_specifier_test(void){return test("hello, world!");}
int		empty_string(void){return test("");}
int		some_escaped_chars(void){return test("\t\n\r\v\f\n");}
int		basic_string_expansion(void){return test("hello, %s.", "gavin");}
