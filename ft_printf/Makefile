# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smortier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:05:13 by smortier          #+#    #+#              #
#    Updated: 2018/01/24 21:39:02 by smortier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE =	ft_printf.c \
			ft_spot_converter.c \
			ft_typing.c \
			ft_memalloc.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strsub.c \
			ft_strlen.c \
			ft_strclen.c \
			ft_parse_attribute.c \
			ft_attribute_htag.c \
			ft_attribute_space.c \
			ft_attribute_plus.c \
			ft_precision_holder.c \
			ft_strcat.c \
			ft_strnew.c \
			ft_strdup.c \
			ft_realloc.c \
			ft_memdel.c \
			ft_memcpy.c \
			ft_attribute_zero.c \
			ft_clear_char.c \
			ft_formate_str.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_get_specifier.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_typing_h.c  \
			ft_typing_hh.c  \
			ft_typing_l.c  \
			ft_typing_ll.c  \
			ft_typing_j.c  \
			ft_typing_z.c  \
			ft_typing_to_str.c \
			ft_itoa.c \
			ft_convert_base.c \
			ft_ulltoa.c  \
			ft_lltoa.c   \
			ft_strrev.c \
			ft_strcpy.c \
			ft_precision_xandup.c \
			ft_precision_s.c \
			ft_precision_pourcent.c \
			ft_attribute_less.c \
			ft_hold_precision_zero.c \
			convert_to_utf_eight.c \
			ft_putstr_ret.c \
			ft_print_unicode.c \
			print_everything.c \
			ft_leaks_holder.c \

NAME = libftprintf.a

OBJET = $(SOURCE:.c=.o)

INCS = -I.

all : $(NAME)

$(NAME) : $(OBJECT)
	@gcc -Wall -Werror -Wextra -c $(SOURCE) $(INCS)
	@ar rc $(NAME) $(OBJET)

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)

re : fclean all
