/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:11:26 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 16:39:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*swb;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		if (s[i] == '\0')
			return (swb = "");
	}
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	swb = ft_memalloc(sizeof(char*) * (end - i + 1));
	while (i <= end)
	{
		swb[j] = s[i];
		i++;
		j++;
	}
	swb[j] = '\0';
	return (swb);
}
