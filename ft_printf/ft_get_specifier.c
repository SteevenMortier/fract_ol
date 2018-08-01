/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:10:12 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 14:10:13 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_it_bfor(char *str, char to_find)
{
	size_t		len;

	len = ft_strlen(str);
	if (len > 1 && str[ft_strlen(str) - 2] == to_find)
		return (1);
	return (0);
}

int		find_it(char *str, char to_find)
{
	size_t		len;

	len = ft_strlen(str);
	if (len && str[ft_strlen(str) - 1] == to_find)
		return (1);
	return (0);
}

void	ls_or_lc_holder(t_conv *conv)
{
	if (conv->type_letter == 'c')
	{
		conv->type_letter = 'C';
		conv->specifier = NULL;
	}
	else if (conv->type_letter == 's')
	{
		conv->type_letter = 'S';
		conv->specifier = NULL;
	}
}

void	get_it(t_conv *conv)
{
	if (find_it(conv->first_arg, 'h'))
	{
		if (find_it_bfor(conv->first_arg, 'h'))
			conv->specifier = "hh";
		else
			conv->specifier = "h";
	}
	else if (find_it(conv->first_arg, 'l'))
	{
		if (find_it_bfor(conv->first_arg, 'l'))
			conv->specifier = "ll";
		else
		{
			if (conv->type_letter == 'c' || conv->type_letter == 's')
				ls_or_lc_holder(conv);
			else
				conv->specifier = "l";
		}
	}
	else if (find_it(conv->first_arg, 'j'))
		conv->specifier = "j";
	else if (find_it(conv->first_arg, 'z'))
		conv->specifier = "z";
}

void	ft_get_specifier(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
			get_it(conv);
		conv = conv->next;
	}
}
