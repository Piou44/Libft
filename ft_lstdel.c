/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:30:05 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/04 11:38:42 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	size_t	content_size;
	t_list	*del_link;
	t_list	*ptr;

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
