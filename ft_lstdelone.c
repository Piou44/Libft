/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:26:02 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 15:10:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*del_link;
	size_t	content_size;

	content_size = (*alst)->content_size;
	del_link = (t_list*)ft_memalloc(sizeof(del_link));
	del_link = *alst;
	del((del_link), content_size);
	free(del_link);
	*alst = NULL;
}
