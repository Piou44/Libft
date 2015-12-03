/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:05:16 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 19:17:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int		i;
	int		res;

	i = 0;
	res = nb;
	if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	else if (power < 0)
	{
		ft_putchar('-');
		power *= -1;
	}
	while (i < power)
	{
		res *= nb;  printf("res = %i\n", res);
		i++;
	}
	return (res);
}

int		main()
{
	printf("%i\n", ft_power(2 ,3));
	return 0;
}
