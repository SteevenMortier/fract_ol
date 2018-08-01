/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_utf_eight.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:46:05 by smortier          #+#    #+#             */
/*   Updated: 2017/12/29 15:47:12 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_to_utf_eight(unsigned int c)
{
	char *string;

	string = ft_strnew(4);
	if (c < 0x80)
		string[0] = (c >> 0 & 0x7F) | 0x00;
	else if (c < 0x0800)
	{
		string[0] = (c >> 6 & 0x1F) | 0xC0;
		string[1] = (c >> 0 & 0x3F) | 0x80;
	}
	else if (c < 0x010000)
	{
		string[0] = (c >> 12 & 0x0F) | 0xE0;
		string[1] = (c >> 6 & 0x3F) | 0x80;
		string[2] = (c >> 0 & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		string[0] = (c >> 18 & 0x07) | 0xF0;
		string[1] = (c >> 12 & 0x3F) | 0x80;
		string[2] = (c >> 6 & 0x3F) | 0x80;
		string[3] = (c >> 0 & 0x3F) | 0x80;
	}
	return (string);
}
