/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_format_pc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:43 by nifromon          #+#    #+#             */
/*   Updated: 2025/02/03 12:53:06 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

int	ftpf_percent_len(const char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ftpf_check_type(s[i]) == 1)
			return (i);
		i++;
	}
	return (0);
}

void	ftpf_format_pc(t_ft_printf *percent, va_list arg)
{
	(void) arg;
	ft_putchar_fd('%', FD);
	percent->printed += 1;
}
