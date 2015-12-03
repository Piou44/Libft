/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:30:05 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 16:22:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	size_t	content_size;
	t_list	*del_link;
	t_list	*ptr;

//	ptr = (t_list*)ft_memalloc(sizeof(t_list));
//	del_link = (t_list*)ft_memalloc(sizeof(t_list));
	del_link = *alst;
	ptr = *alst;
	content_size = (*alst)->content_size;
	while (ptr->next != NULL)
	{
		del(del_link, content_size);
		free(del_link);
		del_link = ptr;
		ptr = ptr->next;
	}
	del(ptr, content_size);
	free(ptr);
	*alst = NULL;
}	

//	REC
///  
/*	size_t	content_size;

	if (*alst != NULL)
	{
		content_size = (*alst)->content_size;
		ft_lstdel(&((*alst)->next), del);
		del((*alst), content_size);
		free(*alst);
		*alst = NULL;
	}
}*/
