/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_star_manager_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:51:29 by nifromon          #+#    #+#             */
/*   Updated: 2025/03/27 06:39:32 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/ft_printf_bonus.h"

int	ftpf_get_index_arg(int idx, const char *format)
{
	int		i;
	int		idx_dollar;
	char	*index;
	
	i = idx;
	idx_dollar = -1;
	while (ftpf_check_type(format[i]) != 1 && format[i])
	{
		if (format[i] == '$')
		{
			idx_dollar = i;
			break ;
		}
		i++;
	}
	if (idx_dollar == -1)
		return (-1);
	index = ft_substr(format, (idx + 1), (idx_dollar - (idx + 1)));
	return (i = ft_atoi(index), free(index), i);
}

int	ftpf_nth_star(int idx, const char *format, t_ft_printf **flags,
		va_list arg)
{
	int		i;
	int		index;
	va_list	arg_copy;
	
	i = 0;
	index = -1;
	va_copy(arg_copy, arg);
	if (format[idx] == '.')
		index = ftpf_get_index_arg((idx + 1), format);
	else if (format[idx] == '*')
		index = ftpf_get_index_arg(idx, format);
	else
		return (va_end(arg_copy), -1);
	if (index > -1)
	{
		while (++i < index)
			va_arg(arg_copy, int);
		if (format[idx] == '.')
			(*flags)->precision = va_arg(arg_copy, int);
		else if (format[idx] == '*')
			(*flags)->width = va_arg(arg_copy, int);
	}
	else
		return (va_end(arg_copy), -1);
	return (va_end(arg_copy), 0);
}

void	ftpf_star_manager(const char *format, t_ft_printf **flags, va_list arg)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while (ftpf_check_type(format[i]) != 1 && format[i])
	{
		if (format[i] == '*' && format[i - 1] == '.')
		{
			if (ftpf_nth_star(i - 1, format, flags, arg) == -1)
				(*flags)->star = 2;
		}
		else if (format[i] == '*')
		{
			if (ftpf_nth_star(i, format, flags, arg) == -1)
				(*flags)->star = 1;
		}
		i++;
	}
	if ((*flags)->star == 1)
		(*flags)->width = va_arg(arg, int);
	else if ((*flags)->star == 2)
		(*flags)->precision = va_arg(arg, int);
	if ((*flags)->precision < -1)
		(*flags)->precision = -1;
}
