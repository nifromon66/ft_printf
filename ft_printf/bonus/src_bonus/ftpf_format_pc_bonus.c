/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_format_pc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:43 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 06:50:56 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

void	ftpf_format_pc(t_ft_printf *percent, va_list arg)
{
	(void) arg;
	ft_putchar_fd('%', FD);
	percent->printed += 1;
}
