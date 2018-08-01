/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:11:52 by smortier          #+#    #+#             */
/*   Updated: 2017/12/08 18:12:34 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		c;
	char	tmp;
	int		i;

	i = 0;
	c = 0;
	while (str[c] != '\0')
		c++;
	c--;
	while (i <= c / 2)
	{
		tmp = str[i];
		str[i] = str[c - i];
		str[c - i] = tmp;
		i++;
	}
	return (str);
}
