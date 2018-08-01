/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:01:46 by smortier          #+#    #+#             */
/*   Updated: 2017/12/14 23:17:45 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_space_case(t_conv *conv)
{
	int		index;
	int		indexbis;

	index = 0;
	while (conv->final_arg[++index] && index < (int)ft_strlen(conv->final_arg)
		&& conv->final_arg[index] == ' ')
	{
		indexbis = index;
		while (conv->final_arg[++indexbis] && conv->final_arg[indexbis] == ' ')
			;
		if (conv->final_arg[indexbis] == '\0')
			return ;
		conv->final_arg[index] = conv->final_arg[indexbis];
		conv->final_arg[indexbis] = ' ';
	}
}

void		ft_hold_less(t_conv *conv, char *spaceorno)
{
	int		index;
	int		indexbis;

	if (!spaceorno && conv->type_letter != '%')
	{
		index = -1;
		while (conv->final_arg[++index] &&
				index < (int)ft_strlen(conv->final_arg) &&
				conv->final_arg[index] == ' ')
		{
			indexbis = index;
			while (conv->final_arg[++indexbis] &&
					conv->final_arg[indexbis] == ' ')
				;
			if (conv->final_arg[indexbis] == '\0')
				return ;
			conv->final_arg[index] = conv->final_arg[indexbis];
			conv->final_arg[indexbis] = ' ';
		}
	}
	else
		ft_space_case(conv);
}

void		ft_attribute_less(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
		{
			if (ft_strchr(conv->first_arg, '-') && conv->final_arg)
			{
				if (!conv->modified)
					ft_hold_less(conv, ft_strchr(conv->first_arg, ' '));
				else
					ft_hold_less(conv, NULL);
			}
		}
		conv = conv->next;
	}
}
