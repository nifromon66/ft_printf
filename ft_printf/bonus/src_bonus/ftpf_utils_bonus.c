/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:38:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/25 02:16:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

static size_t	ull_len(unsigned long long nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_ptrlen(unsigned long long nbr)
{
	int	i;

	i = 0;
	if ((unsigned long long)(LEN_BASE_16 - 1) < nbr)
		i += ft_ptrlen(nbr / LEN_BASE_16);
	i++;
	return (i);
}

char	*ft_ulltoa(unsigned long long n)
{
	size_t				i;
	unsigned long long	nbr;
	char				*result;

	nbr = n;
	i = ull_len(nbr) - 1;
	result = (char *)ft_calloc(ull_len(nbr) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (nbr == 0)
		return (result[0] = '0', result);
	while (nbr > 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	return (result);
}
