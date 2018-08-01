/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:36:46 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 15:36:48 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typing_ll(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_lltoa((long long int)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_strdup(ft_convert_base(
				ft_ulltoa((unsigned long long int)conv->type),
				"0123456789", "01234567"));
	else if (ft_strchr("x", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned long long int)conv->type),
				"0123456789", "0123456789abcdef");
	}
	else if (ft_strchr("X", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned long long int)conv->type),
				"0123456789", "0123456789ABCDEF");
	}
	else if (conv->type_letter == 'u')
		conv->typing = ft_ulltoa((unsigned long long int)conv->type);
	else
		return (0);
	return (1);
}
