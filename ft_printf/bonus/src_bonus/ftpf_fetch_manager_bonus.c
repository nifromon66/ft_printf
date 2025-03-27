/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_fetch_manager_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:33 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 06:37:43 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

int	ftpf_fetch_type(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while ((ftpf_check_type(format[i]) != 1) && format[i])
		i++;
	if (format[i] == 'c')
		return (FT_PRINTF_C);
	else if (format[i] == 's')
		return (FT_PRINTF_S);
	else if (format[i] == 'd')
		return (FT_PRINTF_D);
	else if (format[i] == 'i')
		return (FT_PRINTF_I);
	else if (format[i] == 'u')
		return (FT_PRINTF_U);
	else if (format[i] == 'x')
		return (FT_PRINTF_X_LOW);
	else if (format[i] == 'X')
		return (FT_PRINTF_X_UPP);
	else if (format[i] == '%')
		return (FT_PRINTF_PC);
	return (FT_PRINTF_P);
}

void	ftpf_fetch_flags(const char *format, t_ft_printf **flags)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while ((ftpf_check_type(format[i]) == 2) && format[i])
	{
		if (format[i] == '#')
			(*flags)->hashtag = 2;
		else if (format[i] == '0' && ft_isdigit(format[i - 1]) == 0)
			(*flags)->zero = 1;
		else if (format[i] == '-')
			(*flags)->hyphen = 1;
		else if (format[i] == ' ')
			(*flags)->blank = 1;
		else if (format[i] == '+')
			(*flags)->plus = 1;
		else if (format[i] == '.' && (*flags)->precision == -1)
			(*flags)->precision = ftpf_fetch_precision(format, i);
		else if (ft_isdigit(format[i]) == 1 && (*flags)->width == 0)
			(*flags)->width = ftpf_fetch_width(format, i);
		i++;
	}
	ftpf_sort_flags_manager(flags);
}

int	ftpf_fetch_precision(const char *format, int index)
{
	int		i;
	int		len;
	char	*accuracy;
	int		precision;

	i = index + 1;
	len = 0;
	while (ft_isdigit(format[i]) == 1 && format[i])
		i++;
	len = i;
	accuracy = ft_substr(format, (index + 1), len);
	precision = ft_atoi(accuracy);
	free(accuracy);
	if (precision < -1)
		precision = -1;
	return (precision);
}

int	ftpf_fetch_width(const char *format, int index)
{
	int		i;
	int		len;
	char	*lenght;
	int		width;

	i = index;
	len = 0;
	while (ft_isdigit(format[i]) == 1 && format[i])
		i++;
	len = i;
	lenght = ft_substr(format, index, len);
	width = ft_atoi(lenght);
	free(lenght);
	return (width);
}
