/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:44:18 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 19:44:24 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa(unsigned long long int n)
{
	long				size;
	char				*res;
	unsigned long long	ncpy;

	ncpy = n;
	size = 0;
	size = (n <= 0) ? size + 1 : size;
	while (ncpy)
	{
		ncpy /= 10;
		size++;
	}
	if (!(res = ft_strnew(size)))
		return (NULL);
	size--;
	res[0] = '0';
	ncpy = n;
	while (ncpy)
	{
		res[size] = ncpy % 10 + 48;
		ncpy /= 10;
		size--;
	}
	return (res);
}
