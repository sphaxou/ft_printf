# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 11:50:00 by vgallois          #+#    #+#              #
#    Updated: 2019/12/13 10:21:24 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_printf_x.c\
	  ft_printf_c.c\
	  ft_printf_d.c\
	  ft_printf_u.c\
	  ft_printf_s.c\
	  ft_printf_p.c\
	  ft_printf_o.c\
	  ft_printf_pad.c\
	  ft_printf_percent.c\
	  ft_printf_getfunct.c\
	  ft_printf_parse.c\
	  ft_printf_handle_uint.c\
	  ft_printf_nbrlen.c\
	  ft_min.c\
	  ft_max.c\
	  ft_bzero.c\
	  ft_strlen.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putnbrbase.c\

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

INCLUDES = $(INCDIR)ft_printf.h

INCDIR = ./
SRCDIR = ./src/
OBJDIR = ./obj/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME):	 $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
