/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:00:57 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 18:50:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**fresh_lst;
//	t_list *tmp;
//	t_list *tmp2;

	fresh_lst = ((t_list**)ft_memalloc(sizeof(t_list *)));
	*fresh_lst = NULL;
	while (lst != NULL)
	{
		
	//	tmp = f(lst);
	//	if (!(tmp2 = ft_lstnew(tmp->content, tmp->content_size)))
	//		return (NULL);;
		ft_lstaddend(fresh_lst, f(lst));
//		free(tmp2);
		lst = lst->next;
	}
	return (*fresh_lst);
}
