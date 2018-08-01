/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:40:58 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 15:41:00 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typing_l(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_lltoa((long int)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(ft_ulltoa((unsigned long int)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("x", conv->type_letter))
		conv->typing = ft_convert_base(ft_ulltoa((unsigned long int)conv->type),
				"0123456789", "0123456789abcdef");
	else if (ft_strchr("X", conv->type_letter))
		conv->typing = ft_convert_base(ft_ulltoa((unsigned long int)conv->type),
				"0123456789", "0123456789ABCDEF");
	else if (ft_strchr("c", conv->type_letter))
	{
		conv->typing = ft_strnew(sizeof(wchar_t));
		conv->typing[0] = (wchar_t)conv->type;
	}
	else if (conv->type_letter == 'u')
		conv->typing = ft_ulltoa((unsigned long int)conv->type);
	else
		return (0);
	return (1);
}
