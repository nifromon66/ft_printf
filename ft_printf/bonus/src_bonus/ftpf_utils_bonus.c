/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:38:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/24 22:05:58 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

int	ull_len(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
