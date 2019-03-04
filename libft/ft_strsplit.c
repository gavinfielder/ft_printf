/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:21:09 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/13 19:57:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void			destroy_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ft_memdel((void **)lst);
		*lst = tmp;
	}
}

/*
** Note this takes the last entry in the array and the head of the list
*/

static void			list_to_arr(t_list **lst, char **entry, int *failed)
{
	if ((*lst)->content != NULL)
	{
		list_to_arr(&((*lst)->next), entry - 1, failed);
		*entry = ft_strsub((*lst)->content, 0, (*lst)->content_size);
		if (*entry == NULL)
			*failed = 1;
	}
}

static int			list_words(char const *s, char delim, t_list **lst)
{
	unsigned int	i;
	int				words;
	unsigned int	prev_delim;
	t_list			*head;

	i = 0;
	words = 0;
	prev_delim = 1;
	while (s[i])
	{
		if (prev_delim && s[i] != delim)
		{
			words++;
			head = ft_lstnew_byref(s + i, 1);
			if (head == NULL)
				return (-1);
			ft_lstadd(lst, head);
		}
		else if (!prev_delim && s[i] != delim)
			(*lst)->content_size++;
		prev_delim = (s[i] == delim);
		i++;
	}
	return (words);
}

char				**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**arr;
	t_list	*lst;
	int		failed;

	if (s == NULL)
		return (NULL);
	lst = ft_lstnew_byref(NULL, 0);
	if (lst == NULL)
		return (NULL);
	count = list_words(s, c, &lst);
	if (count < 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr[count] = 0;
	failed = 0;
	list_to_arr(&lst, arr + count - 1, &failed);
	destroy_list(&lst);
	if (failed)
		return (NULL);
	return (arr);
}
