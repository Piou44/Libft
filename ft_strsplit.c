/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:03 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/01 23:04:41 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_str(char *s, char c)
{
	int		i;
	int		n;
	int		len;

	i = 0;
	n = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c &&  i != 0 && i != len && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

char**		count_char(char *s, char c)
{
	int	nb_str;
	char	**tab = NULL;
	int	i;
	int	j = 0;
	int	ok;

	i = 0;
	ok = 0;
	nb_str = count_str(s, c);
	while (s[i] && j < nb_str)
	{
		ok = 0;
		while (s[i] != c)
		{
			i++;
			ok = 1;
			if (s[i + 1] != c)
				break;
		}
		if (i && ok)
			tab[j++] = (char*)ft_memalloc(sizeof(char*) * i + 1);
		i++;
	}
	return (tab);

}
/*
char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dst;

	dst = (char*)malloc(sizeof(char*) * (n + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] || i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
*/
int	find_start(char *s, char c)
{	
	int	j;
	int	start;

	j = 0;
	start = 0;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c)
		{
			start = j + 1;
			return (start);
		}
		j++;
	}
	return (start);
}

int	find_end(char *s, char c)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
		{
			end = i;
			return (end);
		}
		i++;
	}
	return (end);
}

char	*new_str(char *s, char c, int end, int start)
{
	int	i;
	char	*s_char;

	i = start;
	s_char = (char*)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	s_char = (char*)s;
	while (i <= end)
	{
		s_char[i] = c;
		i++;
	}
	return (s_char);
}

char	**ft_strsplit(char const *s, char c)
{
	char		**tab = NULL;
	char		*tmp;
	int		start;
	int		end;
	int		i;
	char		*s_char;

	tmp = NULL;
	start = 0;
	end = 0;
	i = 0;
	s_char = (char*)s;
	tab = (char**)malloc(sizeof(char*) * (count_str(s_char, c)));
	tab = count_char(s_char, c);
	while (i < count_str(s_char, c))
	{
		start = find_start(s_char, c);
		end = find_end(s_char, c);
		tmp = ft_memalloc(sizeof(char*) * end - start + 1);
		tmp = ft_strdup(&s[start]);
		ft_strncpy(tmp, &s_char[start], end - start + 1);
		ft_strcpy(tab[i++], tmp);
		s_char = new_str(s_char, c, end, start);
	}
	return (tab);
}
