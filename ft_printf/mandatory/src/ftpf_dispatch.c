/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:22:36 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/25 15:25:27 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "../headers/ft_printf.h"

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
	int			specifier;

	type = ftpf_init_struct();
	if (format && type)
	{
		specifier = ftpf_fetch_type(format);
		type->specifier = specifier;
	}
	ftpf_dispatching(type->specifier, type, arg);
	printed = type->printed;
	free(type);
	return (printed);
}

//END