/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_htag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:40:48 by smortier          #+#    #+#             */
/*   Updated: 2017/12/03 17:40:49 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			exit_case(t_conv *conv)
{
	if (ft_strlen(conv->typing) == 1 && conv->typing[0] == '0' &&
		conv->type_letter != 'p')
	{
		conv->final_arg[0] = '0';
		return (0);
	}
	else
		return (1);
}

void		ft_attribute_htag(t_conv *conv)
{
	int		i;
	int		y;

	if (ft_strchr("oxXOp", conv->type_letter))
		conv->final_arg = ft_strnew((ft_strlen(conv->typing) + 2));
	if (!exit_case(conv) || !(ft_strchr("oxXOp", conv->type_letter)))
		return ;
	i = 0;
	y = 0;
	while ((unsigned long)i < ft_strlen(conv->typing) + 2)
	{
		if (i == 0)
			conv->final_arg[i] = '0';
		else if (i == 1 && ft_strchr("xp", conv->type_letter))
			conv->final_arg[i] = 'x';
		else if (i == 1 && conv->type_letter == 'X')
			conv->final_arg[i] = 'X';
		else
		{
			conv->final_arg[i] = conv->typing[y];
			y++;
		}
		i++;
	}
}
