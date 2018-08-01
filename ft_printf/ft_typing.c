/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:22:44 by smortier          #+#    #+#             */
/*   Updated: 2017/12/01 19:22:45 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_typing(t_conv *conv, va_list arg)
{
	int		i;

	i = -1;
	while (conv)
	{
		if (conv->type_letter && conv->type_letter != '5')
			conv->type = va_arg(arg, void *);
		if (conv->type_letter == '5')
		{
			if (conv->first_arg[ft_strlen(conv->first_arg) - 1] != '%')
			{
				while (ft_strchr("+-. 0123456789", conv->first_arg[++i]))
					;
				conv->special = ft_strsub(conv->first_arg, i,
					ft_strlen(conv->first_arg) - i);
				conv->type = conv->special;
			}
			else
				conv->type = "%";
			conv->type_letter = 's';
			conv->modified = 1;
		}
		conv = conv->next;
	}
	va_end(arg);
}
