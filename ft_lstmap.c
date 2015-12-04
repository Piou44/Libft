/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:00:57 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/04 11:33:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		**fresh_lst;
	t_list		*new_link;

	fresh_lst = ((t_list**)ft_memalloc(sizeof(t_list *)));
	*fresh_lst = NULL;
	while (lst != NULL)
	{
		new_link = (t_list*)ft_memalloc(sizeof(t_list));
		new_link = f(lst);
		ft_lstaddend(fresh_lst, new_link);
		free(new_link);
		lst = lst->next;
	}
	return (*fresh_lst);
}
