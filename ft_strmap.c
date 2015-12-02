/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:13:59 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:33:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*fresh_s;
	int			i;

	fresh_s = (char*)malloc(sizeof(char*) * (strlen(s) + 1));
	if (fresh_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh_s[i] = f(s[i]);
		i++;
	}
	return (fresh_s);
}
