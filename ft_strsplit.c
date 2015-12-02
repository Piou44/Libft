/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:03 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 19:21:55 by fhuang           ###   ########.fr       */
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

int		count_char(char *s, char c)
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

char	*new_str(char *s, char c, int n)
{
	int		i;

	i = 0;
	while (i < n && s[i])
	{
		s[i] = c;
		i++;
	}
	return (s);
}

char	*trim_c(char *s, char c)
{
	char	*swb;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = ft_strlen(s) - 1;
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0'){ ft_putchar('2');
			return (s + i);}
	}
	while (s[end] == c)
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

int		check_str(char *s, char c)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while(s[i])
	{
		if (s[i] == c)
			ok = 1;
		if (ok)
		{
			if (s[i] != c)
				return (1);
		}
		i++;
	}
	if (!ok)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
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
		tab[j] = (char*)ft_memalloc(sizeof(char) * (count_char(str + i, c) + 1));
		while (str[i] && str[i] == c)
			i++;
		if (count_char(str + i, c) > 0)
			ft_strncpy(tab[j], (str + i), count_char(str + i, c));
		while (str[i] && str[i] != c)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int		main()
{
	char s[] = "*Salut*les***etudiants***";
	char p[] = "COucou";
	char o[] = "";
	char w[] = "****";
	char q[] = "***salut*****!**";
	int	i;
	char	**tab;
	char *tmp;

	i = 0;
	tab = ft_memalloc(sizeof(char*) * (ft_strlen(s) + 1));
	printf("nb str :%i\n", count_str("*Salut*les*etudi***", '*'));
	printf("nb char :%i\n", count_char("*Salut*les*etudi***", '*'));
//	printf("s : %i\n", check_str(s, '*'));
//	printf("p : %i\n", check_str(p, '*'));
//	printf("o : %i\n", check_str(o, '*'));
//	printf("w : %i\n", check_str(w, '*'));

	
	tab = ft_strsplit(s, '*');
	printf("str0 : %s\n", tab[0]);
	printf("str1 : %s\n", tab[1]);
	printf("str2 : %s\n", tab[2]);
	printf("str3 : %s\n", tab[3]);
	return 0;
}
