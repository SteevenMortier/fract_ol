/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:56:48 by smortier          #+#    #+#             */
/*   Updated: 2017/12/29 16:00:33 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_ret(char *str, int printorno)
{
	int		i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i] && i < MB_CUR_MAX)
	{
		if (printorno)
			ft_putchar(str[i]);
	}
	ft_memdel((void **)&str);
	return (i);
}
