/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:22:28 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/26 16:56:34 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_stringbuilder *sb = ft_sbnew();
	ft_sbwrite(sb, "hello ");
	ft_sbwrite(sb, "world ");
	ft_sbwriten(sb, "and back again, but this should not be printed.", 14);
	ft_sbwrite(sb, ". Rather, print this instead.");
	char *str = ft_sbtostr(sb);
	printf("\"%s\"\n", str);
	free (str);

	ft_sbclear(sb);
	ft_sbwrite(sb, "starting a new string now... [");
	ft_sbwrite(sb, "");
	ft_sbwriten(sb, "none of this should be printed", 0);
	ft_sbwrite(sb, NULL);
	ft_sbwriten(sb, NULL, 5);
	ft_sbwriten(sb, "", 17);
	ft_sbwrite(sb, "] < should be empty square brackets.");
	ft_sbwrite(sb, " We can also write\nnewlines into our string!");
	str = ft_sbtostr(sb);
	printf("\"%s\"\n", str);
	free(str);

	ft_sbdel(&sb);

	printf("done with tests. Now entering infinite loop for leaks test.\n");
	while (1);
	return (0);
}
