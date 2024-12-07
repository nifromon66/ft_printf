# **************************************************************************** #
#  #
# :::  ::::::::#
#Makefile   :+:  :+::+:#
# +:+ +:+ +:+  #
#By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+ #
# +#+#+#+#+#+   +#+#
#Created: 2024/11/15 23:58:07 by nifromon  #+##+#  #
#Updated: 2024/11/16 00:15:56 by nifromon ###   ########.fr#
#  #
# **************************************************************************** #

NAME =				libftprintf.a

CC =				gcc
CFLAGS =			-Wall -Wextra -Werror

AR =				ar -rcs
RM =				rm -rf

LIBFT_PATH =		./headers/libft
LIBFT =				$(LIBFT_PATH)/libft.a

TESTER_PATH =		./.tester

SRCS_DIR =			src

SRCS =				\
					$(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/check.c \
					$(SRCS_DIR)/init.c $(SRCS_DIR)/print_format_c.c \
					$(SRCS_DIR)/print_format_s.c $(SRCS_DIR)/print_format_p.c \
					$(SRCS_DIR)/print_format_d.c $(SRCS_DIR)/print_format_i.c \
					$(SRCS_DIR)/print_format_u.c $(SRCS_DIR)/print_format_x_low.c \
					$(SRCS_DIR)/print_format_x_upp.c

OBJS_DIR =			obj

OBJS =				${SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	cp	$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

tester: all
	make -C $(TESTER_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(TESTER_PATH) clean
	$(RM) a.out $(OBJS_DIR)

fclean: clean
	make -C $(TESTER_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all tester clean fclean re

#END