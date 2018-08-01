/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:35:25 by smortier          #+#    #+#             */
/*   Updated: 2017/11/30 16:35:29 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <cxxabi.h>
# include <wchar.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_conv
{
	char			*first_arg;
	char			*typing;
	char			*final_arg;
	char			type_letter;
	size_t			precision;
	size_t			lenght_min;
	char			*specifier;
	void			*type;
	char			*special;
	wchar_t			*final_argw;
	int				modified;
	struct s_conv	*next;
	struct s_conv	*prev;
}						t_conv;

int						ft_spot_converter(char c);

void					ft_typing(t_conv *conv, va_list arg);

int						ft_printf(const char *restrict format, ...);

void					ft_parse_attribute(t_conv *conv);

void					ft_attribute_htag(t_conv *conv);

void					ft_attribute_zero(t_conv *conv);

void					ft_attribute_less(t_conv *conv);

void					ft_hold_precision_zero(t_conv *conv);

void					ft_attribute_space(t_conv *conv);

void					ft_attribute_plus(t_conv *conv);

void					ft_precision_holder(t_conv *conv);

char					*ft_clear_char(char *str, char c);

void					ft_formate_str(t_conv *conv);

void					ft_get_specifier(t_conv *conv);

int						ft_typing_hh(t_conv *conv);

int						ft_typing_h(t_conv *conv);

int						ft_typing_ll(t_conv *conv);

int						ft_typing_l(t_conv *conv);

int						ft_typing_j(t_conv *conv);

int						ft_typing_z(t_conv *conv);

void					ft_precision_xandup(t_conv *conv);

void					ft_typing_to_str(t_conv *conv);

void					ft_precision_s(t_conv *conv);

void					ft_precision_pourcent(t_conv *conv);

char					*ft_convert_base(char *nbr, char *base_from,
										char *base_to);

char					*ft_lltoa(long long int n);

char					*ft_ulltoa(unsigned long long int n);

char					*ft_strrev(char *str);

char					*convert_to_utf_eight(unsigned int c);

int						ft_putstr_ret(char *str, int printorno);

int						ft_print_unicode(t_conv *conv);

int						print_everything(t_conv *conv);

int						ft_leaks_holder(t_conv *conv);

#endif
