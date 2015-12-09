/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynam_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 21:44:48 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 16:18:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dynam_append(t_dynam *dynam, void *new_data, size_t nb_newdata)
{
	size_t	mult;
	void	*tmp;

	mult = 1;
	while (nb_newdata + dynam->nb_elem > mult * dynam->max_elem)
		mult *= 2;
	if (mult > 1)
	{
		dynam->max_elem *= mult;
		if (!(tmp = malloc(dynam->max_elem * dynam->type_size)))
			return (1);
		ft_memcpy(tmp, dynam->data, (dynam->nb_elem * dynam->type_size));
		free(dynam->data);
		dynam->data = tmp;
	}
	ft_memcpy(dynam->data + dynam->nb_elem * dynam->type_size,
	new_data, nb_newdata * dynam->type_size);
	dynam->nb_elem += nb_newdata;
	return (0);
}
