/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:25:10 by smortier          #+#    #+#             */
/*   Updated: 2018/01/08 15:27:33 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unicode_precision(t_conv *conv)
{
	int		index;
	int		index_uni;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (conv->final_argw[i])
	{
		i2 += ft_putstr_ret(convert_to_utf_eight(conv->final_argw[i]), 0);
		i++;
	}
	index = -1;
	index_uni = 0;
	while (++index < (int)conv->lenght_min - i2)
		ft_putchar(' ');
	while (index < ((int)conv->lenght_min))
	{
		index += ft_putstr_ret(convert_to_utf_eight(
				conv->final_argw[index_uni]), 1);
		index_uni++;
	}
	return (index);
}

int		ft_unicode_precicion_atr_less(t_conv *conv)
{
	int		index;
	int		index_uni;

	index = 0;
	index_uni = 0;
	while (index < (int)conv->lenght_min)
	{
		if (conv->final_argw[index_uni])
		{
			index += ft_putstr_ret(
					convert_to_utf_eight(conv->final_argw[index_uni]), 1);
			index_uni++;
		}
		else
		{
			ft_putchar(' ');
			index++;
		}
	}
	return (index);
}

int		ft_print_unicode(t_conv *conv)
{
	int		ret;
	int		i;
	int		y;

	i = 0;
	y = 0;
	ret = 0;
	if (conv->lenght_min)
	{
		if (ft_strchr(conv->first_arg, '-'))
			ret = ft_unicode_precicion_atr_less(conv);
		else
			ret = ft_unicode_precision(conv);
	}
	else
	{
		while (conv->final_argw[i])
		{
			y += ft_putstr_ret(convert_to_utf_eight(conv->final_argw[i]), 1);
			i++;
		}
		ret = y;
	}
	return (ret);
}
