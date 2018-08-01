/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:00:21 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 16:00:22 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typing_z(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_lltoa((size_t)conv->type);
	else if (conv->type_letter == 'u')
		conv->typing = ft_ulltoa((size_t)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(ft_ulltoa((size_t)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("x", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((uintmax_t)conv->type),
				"0123456789", "0123456789abcdef");
	}
	else if (ft_strchr("X", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((uintmax_t)conv->type),
				"0123456789", "0123456789ABCDEF");
	}
	else
		return (0);
	return (1);
}
