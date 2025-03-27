/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_dispatch_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:52:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 06:48:53 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

void	ftpf_dispatching(int type, t_ft_printf *format, va_list arg)
{
	t_ftpf_dispatch	arr[9];

	arr[FT_PRINTF_C] = &ftpf_format_c;
	arr[FT_PRINTF_S] = &ftpf_format_s;
	arr[FT_PRINTF_P] = &ftpf_format_p;
	arr[FT_PRINTF_D] = &ftpf_format_d;
	arr[FT_PRINTF_I] = &ftpf_format_i;
	arr[FT_PRINTF_U] = &ftpf_format_u;
	arr[FT_PRINTF_X_LOW] = &ftpf_format_x_low;
	arr[FT_PRINTF_X_UPP] = &ftpf_format_x_upp;
	arr[FT_PRINTF_PC] = &ftpf_format_pc;
	arr[type](format, arg);
}

int	ftpf_parsing(const char *format, va_list arg)
{
	t_ft_printf	*type;
	int			printed;

	printed = 0;
	type = ftpf_init_struct();
	if (format && type)
	{
		type->specifier = ftpf_fetch_type(format);
		ftpf_star_manager(format, &type, arg);
		ftpf_fetch_flags(format, &type);
		ftpf_dispatching(type->specifier, type, arg);
		printed = type->printed;
		free(type);
	}
	return (printed);
}
