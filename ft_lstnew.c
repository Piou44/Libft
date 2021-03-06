/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:29:54 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 15:29:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh_link;

	if (!(fresh_link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		fresh_link->content = NULL;
		fresh_link->content_size = 0;
	}
	else
	{
		fresh_link->content = malloc(sizeof(*content) * content_size);
		if (!fresh_link)
			return (NULL);
		ft_memcpy(fresh_link->content, content, content_size);
		fresh_link->content_size = content_size;
	}
	fresh_link->next = NULL;
	return (fresh_link);
}
