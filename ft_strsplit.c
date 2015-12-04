/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:03 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/04 11:31:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char *s, char c)
{
	int		i;
	int		n;
	int		len;

	i = 0;
	n = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				n++;
		}
	}
	return (n);
}

static int	count_char(char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] != c)
		{
			i++;
			n++;
			if (s[i] == c || s[i] == '\0')
				break ;
		}
		if (n)
			break ;
		i++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char*)s;
	tab = (char**)ft_memalloc(sizeof(char*) * (count_str(str, c) + 1));
	while (str[i])
	{
		str = ft_trim_c(str, c);
		tab[j] = (char*)ft_memalloc(sizeof(char) *
			(count_char(str + i, c) + 1));
		while (str[i] && str[i] == c)
			i++;
		if (count_char(str + i, c) > 0)
		{
			ft_strncpy(tab[j++], (str + i), count_char(str + i, c));
			while (str[i] && str[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
