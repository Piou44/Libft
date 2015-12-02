/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:47:57 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/01 17:51:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		count_n(unsigned int n)
{
	unsigned int		i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*n_negative(int n)
{
	char				*res;
	int					i;
	int					tmp;
	unsigned int		n_cast;

	n_cast = (unsigned int)-n;
	res = ft_memalloc(sizeof(char*) * count_n(n_cast) + 2);
	tmp = 0;
	res[0] = '-';
	i = count_n(n_cast);
	res[i + 1] = '\0';
	while (n_cast >= 10)
	{
		tmp =  n_cast % 10;
		res[i] = tmp + '0';
		i--;
		n_cast /= 10;
	}
	res[1] = n_cast % 10 + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		tmp;
	int		i;
	
	i = 0;
	tmp = 0;
	if (n < 0)
		res = n_negative(n);
	else
	{
		res = ft_memalloc(sizeof(char*) * (count_n(n) + 1));
		i = (count_n(n) - 1);
		res[i] = '\0';
		while (n >= 10)
		{
			tmp = n % 10;
			res[i] = tmp + '0';
			i--;
			n /= 10;
		}
		res[0] = n % 10 + '0';
	}
	return (res);
}
