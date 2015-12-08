/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:02 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 18:51:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		len_dst;
	size_t		len_src;

	n = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size > len_dst)
	{
		n = size - len_dst - 1;
		ft_strncpy(&dst[len_dst], src, n);
		return (len_dst + len_src);
	}
	else if (size < len_dst)
		return (size + len_src);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int		main()
{
	char	buf[] = "Nooope";
	char	dst1[8] = "ok";
	char	dst2[8] = "ok";
	strlcat(dst1, buf, 4);
	ft_strlcat(dst2, buf, 4);

	printf("V : %s\n", dst1);
	printf("V : %c\n", dst1[strlen(dst1)]);
	printf("F : %s\n", dst2);
	printf("F : %c\n", dst2[strlen(dst2)]);
	return 0;
}*/
