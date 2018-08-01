/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:30:11 by smortier          #+#    #+#             */
/*   Updated: 2017/11/30 16:30:12 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

t_conv		*ft_newconv(char *str, char c)
{
	t_conv		*newconv;

	if (!(newconv = (t_conv *)ft_memalloc(sizeof(t_conv))))
		return (NULL);
	newconv->first_arg = str;
	newconv->typing = NULL;
	newconv->final_arg = NULL;
	newconv->type_letter = c;
	newconv->specifier = NULL;
	newconv->type = NULL;
	newconv->precision = 0;
	newconv->modified = 0;
	newconv->next = NULL;
	newconv->prev = NULL;
	newconv->final_argw = NULL;
	return (newconv);
}

t_conv		*ft_create_lst(t_conv *conv, char *str, char c)
{
	t_conv *temp;

	if (conv == NULL)
		return (ft_newconv(str, c));
	else
	{
		temp = conv;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_newconv(str, c);
		temp->next->prev = temp;
		return (conv);
	}
}

t_conv		*norme_help_lst(t_conv *conv, char *format, unsigned int index,
							unsigned int index_prc)
{
	if ((!ft_strchr("dDiIuUoOxXcCsSp", format[index + index_prc])))
		conv = ft_create_lst(conv,
							ft_strsub(format, index, index_prc + 1), '5');
	else
	{
		conv = ft_create_lst(conv,
							ft_strsub(format, index, index_prc),
							format[index + index_prc]);
	}
	return (conv);
}

t_conv		*ft_fill_lst(t_conv *conv, char *format)
{
	unsigned int	index;
	unsigned int	index_prc;

	index = 0;
	while (format[index] && index < ft_strlen(format))
	{
		index_prc = 0;
		if (format[index] == '%' && ++index)
		{
			while (format[index + index_prc] &&
					ft_spot_converter(format[index + index_prc]))
				index_prc++;
			conv = norme_help_lst(conv, format, index, index_prc);
			index += index_prc + 1;
		}
		else
		{
			while (format[index + index_prc] &&
					format[index + index_prc] != '%')
				index_prc++;
			conv = ft_create_lst(conv, ft_strsub(format, index, index_prc), 0);
			index += index_prc;
		}
	}
	return (conv);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list			arg;
	t_conv			*conv;
	int				ret;

	conv = NULL;
	conv = ft_fill_lst(conv, (char *)format);
	ft_formate_str(conv);
	ft_get_specifier(conv);
	va_start(arg, format);
	ft_typing(conv, arg);
	va_end(arg);
	ft_typing_to_str(conv);
	ft_parse_attribute(conv);
	ft_attribute_zero(conv);
	ft_attribute_less(conv);
	ft_hold_precision_zero(conv);
	ret = print_everything(conv);
	if (!ft_leaks_holder(conv))
		return (0);
	return (ret);
}
