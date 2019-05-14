# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalkins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:53:58 by acalkins          #+#    #+#              #
#    Updated: 2019/04/08 18:23:29 by acalkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
SRC		= ft_putchar.c \
		  ft_putstr.c \
		  ft_putnstr_fd.c \
		  ft_putnstr.c \
		  ft_print_pad.c \
		  ft_putnbr.c \
		  ft_isdigit.c \
		  ft_strsub.c \
		  int_length.c \
		  ft_memset.c \
		  ft_memalloc.c \
		  ft_strnew.c \
		  ft_ctostr.c \
		  ft_strlen.c \
		  put_uprecision.c \
		  ft_strjoin.c \
		  ft_strrev.c \
		  ft_uitobase.c \
		  ft_uitooctal.c \
		  ft_countdigit.c \
		  ft_countdigit_unsigned.c \
		  ft_strdel.c \
		  ft_strlcat.c \
		  ft_strcpy.c \
		  ft_strjoincl.c \
		  ft_wctostr.c \
		  ft_strdup.c \
		  ft_imtoa.c \
		  ft_uimtoa.c \
		  ft_strncmp.c \
		  ft_strcmp.c \
		  ft_bzero.c \
		  ft_uitohex.c \
		  ft_nwstostr.c \
		  ft_wstostr.c \
		  ft_unsigned_from_length.c \
		  ft_signed_from_length.c \
		  ft_print_u.c \
		  ft_print_upper_s.c \
		  ft_print_s.c \
		  ft_print_upper_c.c \
		  ft_print_c.c \
		  ft_print_upper_x.c \
		  ft_print_per.c \
		  ft_print_x.c \
		  ft_get_nbstr.c \
		  put_sign.c \
		  put_precision.c \
		  ft_print_d.c \
		  ft_printf_o.c \
		  flag_check.c \
		  ft_get_flags.c \
		  ft_get_width.c \
		  ft_get_precision.c \
		  ft_get_len_modifier.c \
		  ft_get_args.c \
		  ft_printf_p.c \
		  inner_print.c \
		  step_one.c \
		  printfer.c \
		  ft_printf.c

OBJ		= $(SRC:.c=.o)

INC		= libft.h

OBJDIR	= ./objs/

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME):
		@gcc $(FLAG) -c $(SRC) -I$(INC)
		@mkdir -p $(OBJDIR)
		@mv	$(OBJ) $(OBJDIR)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJS)
		@rm -rf $(OBJDIR)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
