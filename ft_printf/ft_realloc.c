/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:33:16 by smortier          #+#    #+#             */
/*   Updated: 2018/01/10 19:33:18 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_realloc(void **ptr, size_t oldsize, size_t newsize)
{
	void	*freshptr;

	if (!(freshptr = ft_strnew(newsize)))
		return (NULL);
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, oldsize);
		ft_memdel(ptr);
	}
	return (freshptr);
}
