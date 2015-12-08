/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:07:56 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:26:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	while (n > 0)
	{
		dst[i++] = '\0';
		n--;
	}
	return (dst);
}

#include <string.h>
#include <stdio.h>
int		main()
{
	char	buf[] = "--> nyancat <--\n\r";
	char	dst1[30] = {[29]='a'};
	char	dst2[30] = {[29]='a'};
	strncpy(dst1, buf, 12);
	ft_strncpy(dst2, buf, 12);
	printf("CMP : %d\n", strcmp(dst1, dst2));
	printf("V : %s\n", dst1);
	printf("F : %s\n", dst2);
	return 0;
}
