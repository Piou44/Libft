/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:35:49 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:32:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
