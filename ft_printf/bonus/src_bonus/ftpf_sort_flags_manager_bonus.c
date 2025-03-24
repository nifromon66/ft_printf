/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_sort_flags_manager_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:06:23 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/24 22:04:19 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

void	ftpf_sort_flags_manager(t_ft_printf **flags)
{
	ftpf_sort_flags_spec(flags, (*flags)->specifier);
	if ((*flags)->plus != 0)
		(*flags)->blank = 0;
	if ((*flags)->hyphen != 0 || (*flags)->precision != -1)
		(*flags)->zero = 0;
	if ((*flags)->precision != -1 && (*flags)->width != 0)
		(*flags)->width -= (*flags)->precision;
}

void	ftpf_sort_flags_spec(t_ft_printf **flags, int spec)
{
	if (spec != FT_PRINTF_I && spec != FT_PRINTF_D)
	{
		(*flags)->plus = 0;
		(*flags)->blank = 0;
	}
	if (spec != FT_PRINTF_X_LOW && spec != FT_PRINTF_X_UPP
		&& spec != FT_PRINTF_P)
		(*flags)->hashtag = 0;
	if (spec == FT_PRINTF_C || spec == FT_PRINTF_S || spec == FT_PRINTF_P)
		(*flags)->zero = 0;
	if (spec == FT_PRINTF_C || spec == FT_PRINTF_P || spec == FT_PRINTF_PC)
		(*flags)->precision = -1;
}
