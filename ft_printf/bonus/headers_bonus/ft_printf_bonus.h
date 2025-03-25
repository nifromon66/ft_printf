/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf.h:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 14:57:45 by nifromon  #+##+# */
/*   Updated: 2024/11/16 00:21:51 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include "../../libft/headers/libft.h"

// Macros
# define FD				1
# define NULL_S			"(null)"
# define OX				"0x"
# define LEN_OX 		2
# define NULL_P			"(nil)"
# define BASE_10		"012345678910"
# define LEN_BASE_10	10
# define BASE_16_LOW	"0123456789abcdef"
# define BASE_16_UPP	"0123456789ABCDEF"
# define NULL_HEX		"(nil)"
# define LEN_BASE_16	16
# define INT_MIN_S		"-2147483648"

// Enumerations
typedef enum e_ft_printf
{
	FT_PRINTF_C,
	FT_PRINTF_S,
	FT_PRINTF_P,
	FT_PRINTF_D,
	FT_PRINTF_I,
	FT_PRINTF_U,
	FT_PRINTF_X_LOW,
	FT_PRINTF_X_UPP,
	FT_PRINTF_PC
}	t_enum_ft_printf;

// Structures
typedef struct s_ft_printf
{
	int	hashtag;
	int	zero;
	int	hyphen;
	int	blank;
	int	plus;
	int	width;
	int	precision;
	int	star;
	int	specifier;
	int	printed;
}	t_ft_printf;

// Fonction alias
typedef void	(*t_ftpf_dispatch)(t_ft_printf *format, va_list arg);

// Fonctions
	// ft_printf.c
int			ft_printf(const char *format, ...);
	// ftpf_dispatch_bonus.c
int			ftpf_parsing(const char *format, va_list arg);
void		ftpf_dispatching(int type, t_ft_printf *format, va_list arg);
void		ftpf_format_star(const char *format, t_ft_printf **flags,
				va_list arg);
	// ftpf_init_bonus.c
t_ft_printf	*ftpf_init_struct(void);
	// ftpf_fetch_manager_bonus.c
int			ftpf_fetch_type(const char *format);
void		ftpf_fetch_flags(const char *format, t_ft_printf **flags);
int			ftpf_fetch_precision(const char *format, int index);
int			ftpf_fetch_width(const char *format, int index);
	// ftpf_sort_flags_manager_bonus.c
void		ftpf_sort_flags_manager(t_ft_printf **flags);
void		ftpf_sort_flags_spec(t_ft_printf **flags, int spec);
	// ftpf_check_bonus.c
int			ftpf_check_type(char c);
int			ftpf_check_spec(const char *s);
	// ftpf_format_*.c
void		ftpf_format_c(t_ft_printf *format, va_list arg);
void		ftpf_format_s(t_ft_printf *format, va_list arg);
void		ftpf_format_p(t_ft_printf *format, va_list arg);
void		ftpf_format_d(t_ft_printf *format, va_list arg);
void		ftpf_format_i(t_ft_printf *format, va_list arg);
void		ftpf_format_u(t_ft_printf *format, va_list arg);
void		ftpf_format_x_low(t_ft_printf *format, va_list arg);
void		ftpf_format_x_upp(t_ft_printf *format, va_list arg);
void		ftpf_format_pc(t_ft_printf *percent, va_list arg);
int			ftpf_percent_len(const char *s);
// ftpf_utils_bonus.c
int			ft_ptrlen(unsigned long long nbr);
char		*ft_ulltoa(unsigned long long n);

#endif

//END