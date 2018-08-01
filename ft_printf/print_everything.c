/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:08:07 by smortier          #+#    #+#             */
/*   Updated: 2018/01/10 20:08:09 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		help_for_norm(t_conv *conv)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (conv->type_letter != 'C' && conv->type_letter != 'S')
	{
		ft_putstr(conv->final_arg);
		ret += (int)ft_strlen(conv->final_arg);
	}
	else if (conv->type_letter == 'C' || (conv->type_letter == 'S'))
	{
		if (conv->type)
			ret += ft_print_unicode(conv);
		else
			ret++;
	}
	return (ret);
}

int		check_unicode(wchar_t c)
{
	if (c < 0 || (c >= 0xd800 && c < 0xe000))
		return (0);
	if ((c <= 0x7f && MB_CUR_MAX >= 1) || (c <= 0xff && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 0x7ff && MB_CUR_MAX >= 2)
		return (1);
	else if (c <= 0xffff && MB_CUR_MAX >= 3)
		return (1);
	else if (c <= 0x10ffff && MB_CUR_MAX >= 4)
		return (1);
	return (0);
}

int		null_case(void)
{
	int		ret;

	ret = 0;
	ft_putstr("(null)");
	ret += ft_strlen("(null)");
	return (ret);
}

int		norme_helper(t_conv *conv)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (ft_strchr(conv->first_arg, '-') && conv->lenght_min)
	{
		ft_putchar(0);
		while (++i < (int)conv->lenght_min - 1)
			ft_putchar(' ');
		return ((int)conv->lenght_min);
	}
	else if (!ft_strchr(conv->first_arg, '.'))
	{
		while (++i < (int)ft_strlen(conv->final_arg) - 1)
			(ft_strchr(conv->first_arg, '0') ? ft_putchar('0')
											: ft_putchar(' '));
	}
	ft_putchar(conv->final_arg[ft_strlen(conv->final_arg)]);
	ret += (conv->lenght_min) ? (int)ft_strlen(conv->final_arg) :
		1;
	return (ret);
}

int		print_everything(t_conv *conv)
{
	int		ret;
	int		i;

	ret = 0;
	while (conv)
	{
		if (conv->type_letter == 'C' && conv->type)
			if (!check_unicode((wchar_t)conv->type))
				return (-1);
		if (conv->type_letter == 'S' && conv->type)
		{
			i = -1;
			while (conv->final_argw[++i])
				if (!check_unicode((wchar_t)conv->final_argw[i]))
					return (-1);
		}
		if (!conv->type && conv->type_letter == 'S')
			ret += null_case();
		else if ((conv->type_letter == 'c' && !conv->type))
			ret += norme_helper(conv);
		else
			ret += help_for_norm(conv);
		conv = conv->next;
	}
	return (ret);
}
