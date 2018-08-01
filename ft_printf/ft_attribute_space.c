/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:41:43 by smortier          #+#    #+#             */
/*   Updated: 2017/12/03 17:41:44 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_dexist(t_conv *conv)
{
	int		i;
	size_t	len;

	if (conv->typing[0] == '-')
	{
		conv->final_arg = conv->typing;
		conv->typing = NULL;
	}
	else
	{
		len = ft_strlen(conv->typing);
		conv->final_arg = ft_strnew(len + 1);
		i = 0;
		conv->final_arg[i] = ' ';
		while (conv->typing[i])
		{
			conv->final_arg[i + 1] = conv->typing[i];
			i++;
		}
	}
}

void		ft_attribute_space(t_conv *conv)
{
	if (ft_strchr(conv->first_arg, '+'))
		return ;
	if (!conv->final_arg)
		ft_dexist(conv);
	else
		exit(1);
}
