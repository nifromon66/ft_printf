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

# Arguments
NAME =				libftprintf.a

# Compilation
CC =				@gcc
CFLAGS =			-Wall -Wextra -Werror
INCLUDES =			-I bonus/headers_bonus/

# Utils
AR =				@ar -rcs
RM =				@rm -rf

# Colors
BLACK_ON_GREEN =	\033[30;42m
BLACK_ON_RED =		\033[30;41m
YELLOW =			\033[1;33m
GREEN =				\033[1;32m
RED =				\033[1;31m
RESET =				\033[1;0m

# Libft
LIBFT_PATH =		libft
LIBFT =				$(LIBFT_PATH)/libft.a

# Sources and objects
SRCS_DIR =			bonus/src_bonus

SRCS =				\
					$(SRCS_DIR)/ft_printf_bonus.c \
					$(SRCS_DIR)/ftpf_check_bonus.c \
					$(SRCS_DIR)/ftpf_init_bonus.c \
					$(SRCS_DIR)/ftpf_star_manager_bonus.c \
					$(SRCS_DIR)/ftpf_fetch_manager_bonus.c \
					$(SRCS_DIR)/ftpf_sort_flags_manager_bonus.c \
					$(SRCS_DIR)/ftpf_dispatch_bonus.c \
					$(SRCS_DIR)/ftpf_format_c_bonus.c \
					$(SRCS_DIR)/ftpf_format_s_bonus.c \
					$(SRCS_DIR)/ftpf_format_p_bonus.c \
					$(SRCS_DIR)/ftpf_format_pc_bonus.c \
					$(SRCS_DIR)/ftpf_format_d_bonus.c \
					$(SRCS_DIR)/ftpf_format_i_bonus.c \
					$(SRCS_DIR)/ftpf_format_u_bonus.c \
					$(SRCS_DIR)/ftpf_format_x_low_bonus.c \
					$(SRCS_DIR)/ftpf_format_x_upp_bonus.c

OBJS_DIR =			obj

OBJS =				$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Rules and dependencies
all:				$(NAME) print_end

print_start:
					@echo "$(YELLOW)Building $(NAME)...$(RESET)"

print_end:
					@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

$(NAME): 			$(LIBFT) print_start $(OBJS)
					@cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(LIBFT):
					@make -s -C $(LIBFT_PATH) libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/src
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
					@make -s -C $(LIBFT_PATH) clean_libft
					@echo "$(YELLOW)Cleaning $(NAME)...$(RESET)"
					$(RM) $(OBJS_DIR)
					@echo "$(RED)Cleaned $(NAME)$(RESET)"

fclean: 			clean
					@make -s -C $(LIBFT_PATH) fclean_libft
					@echo "$(YELLOW)Forcefully cleaning $(NAME)...$(RESET)"
					$(RM) $(NAME)
					@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

re: 				fclean all

.PHONY: 			all tester clean fclean re

#END