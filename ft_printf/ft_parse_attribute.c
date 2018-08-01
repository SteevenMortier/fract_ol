/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_attribute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:28:37 by smortier          #+#    #+#             */
/*   Updated: 2017/12/03 17:28:38 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_attribute(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
		{
			if ((ft_strchr(conv->first_arg, '#') || conv->type_letter == 'p'))
				ft_attribute_htag(conv);
			if (ft_strchr(conv->first_arg, '+')
				&& !ft_strchr("%usScCoOpxX", conv->type_letter))
				ft_attribute_plus(conv);
			if (ft_strchr(conv->first_arg, ' ') &&
					!ft_strchr("%usScCoOpxX", conv->type_letter))
				ft_attribute_space(conv);
			if (!conv->final_arg && conv->type_letter != '%')
				conv->final_arg = ft_strdup(conv->typing);
			if ((conv->precision || conv->lenght_min) ||
					ft_strchr(conv->first_arg, '.'))
				ft_precision_holder(conv);
		}
		else
			conv->final_arg = ft_strdup(conv->first_arg);
		conv = conv->next;
	}
}
