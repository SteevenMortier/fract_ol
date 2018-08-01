/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:23:54 by smortier          #+#    #+#             */
/*   Updated: 2017/12/11 22:23:57 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_dexistplus(t_conv *conv)
{
	int		i;

	if (conv->typing[0] == '-')
	{
		conv->final_arg = conv->typing;
		conv->typing = NULL;
	}
	else
	{
		conv->final_arg = ft_strnew(ft_strlen(conv->typing) + 1);
		i = 0;
		conv->final_arg[i] = '+';
		while (conv->typing[i])
		{
			conv->final_arg[i + 1] = conv->typing[i];
			i++;
		}
	}
}

void		ft_attribute_plus(t_conv *conv)
{
	if (!conv->final_arg)
		ft_dexistplus(conv);
	else
		exit(1);
}
