/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:56:21 by smortier          #+#    #+#             */
/*   Updated: 2017/12/04 16:57:24 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_clear_char(char *str, char c)
{
	int		i;
	int		y;
	int		nb_htag;
	char	*tmp;

	nb_htag = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			nb_htag++;
	i = -1;
	y = -1;
	tmp = ft_strnew(ft_strlen(str) - nb_htag);
	while (str[++i])
	{
		if (str[i] == c)
			i++;
		tmp[++y] = str[i];
	}
	return (tmp);
}
