/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks_holder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:02:50 by smortier          #+#    #+#             */
/*   Updated: 2018/01/14 22:02:53 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_leaks_holder(t_conv *conv)
{
	t_conv		*temp;

	if (conv)
	{
		while (conv)
		{
			temp = conv;
			conv = conv->next;
			ft_memdel((void **)&temp->first_arg);
			ft_memdel((void **)&temp->typing);
			if (temp->type_letter == 'C')
				ft_memdel((void **)&temp->final_argw);
			ft_memdel((void **)&temp->special);
			ft_memdel((void **)&temp->final_arg);
			ft_memdel((void **)&temp);
		}
		return (1);
	}
	return (0);
}
