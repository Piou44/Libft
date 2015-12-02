/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:19:31 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 16:23:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	tmp = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] && s1[i] != s2[j])
			i++;
		tmp = i;
		while (s2[j] && s1[i++] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char*)s1 + tmp);
		else if (s1[i])
			i = tmp + 1;
	}
	if (s1[i] == '\0')
		return (NULL);
	return (0);
}
