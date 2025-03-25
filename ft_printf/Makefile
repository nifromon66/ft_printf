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
NAME_BONUS =		libftprintf.a

CC =				gcc
CFLAGS =			-Wall -Wextra -Werror
INCLUDES =			-I mandatory/headers/
INCLUDES_BONUS =	-I bonus/headers_bonus/

AR =				ar -rcs
RM =				rm -rf

LIBFT_PATH =		libft
LIBFT =				$(LIBFT_PATH)/libft.a

TESTER_PATH =		mandatory/tester_mandatory
TESTER_BONUS_PATH =	bonus/tester_bonus

SRCS_DIR =			mandatory/src
SRCS_BONUS_DIR =	bonus/src_bonus

SRCS =				\
					$(SRCS_DIR)/ft_printf.c \
					$(SRCS_DIR)/ftpf_check.c \
					$(SRCS_DIR)/ftpf_init.c \
					$(SRCS_DIR)/ftpf_format_c.c \
					$(SRCS_DIR)/ftpf_format_s.c \
					$(SRCS_DIR)/ftpf_format_p.c \
					$(SRCS_DIR)/ftpf_format_d.c \
					$(SRCS_DIR)/ftpf_format_i.c \
					$(SRCS_DIR)/ftpf_format_u.c \
					$(SRCS_DIR)/ftpf_format_x_low.c \
					$(SRCS_DIR)/ftpf_format_x_upp.c

OBJS_DIR =			obj

OBJS =				$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRCS_BONUS =		\
					$(SRCS_BONUS_DIR)/ft_printf_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_dispatch_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_check_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_init_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_fetch_manager_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_sort_flags_manager_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_c_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_s_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_p_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_pc_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_d_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_i_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_u_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_x_low_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_format_x_upp_bonus.c \
					$(SRCS_BONUS_DIR)/ftpf_utils_bonus.c

OBJS_BONUS_DIR =	obj_bonus

OBJS_BONUS =		$(SRCS_BONUS:$(SRCS_BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)

all: 				$(NAME)

$(NAME): 			$(LIBFT) $(OBJS)
					cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/src
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

bonus:				$(NAME_BONUS)

$(NAME_BONUS):		$(LIBFT) $(OBJS_BONUS)
					cp $(LIBFT) $(NAME_BONUS)
					$(AR) $(NAME_BONUS) $(OBJS_BONUS)

$(OBJS_BONUS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
					@mkdir -p $(OBJS_BONUS_DIR)
					@mkdir -p $(OBJS_BONUS_DIR)/src_bonus
					$(CC) -c $(CFLAGS) $(INCLUDES_BONUS) $< -o $@

tester: 			all
					make -C $(TESTER_PATH) all

tester_bonus:		bonus
					make -C $(TESTER_BONUS_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(TESTER_PATH) clean
					make -C $(TESTER_BONUS_PATH) clean
					$(RM) $(OBJS_DIR)
					$(RM) $(OBJS_BONUS_DIR)

fclean: 			clean
					make -C $(TESTER_PATH) fclean
					make -C $(TESTER_BONUS_PATH) fclean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re: 				fclean all

re_bonus:			fclean bonus

re_tester:			fclean tester

re_tester_bonus:	fclean tester_bonus

.PHONY: 			all tester clean fclean re \
					bonus tester_bonus re_bonus \
					re_tester re_tester_bonus

#END