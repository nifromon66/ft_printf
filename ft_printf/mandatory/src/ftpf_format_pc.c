/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_format_pc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:21:31 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/25 15:22:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "../headers/ft_printf.h"

void	ftpf_format_pc(t_ft_printf *percent, va_list arg)
{
	(void) arg;
	ft_putchar_fd('%', FD);
	percent->printed += 1;
}

//END