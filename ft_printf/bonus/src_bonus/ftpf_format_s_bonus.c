/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_s.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 19:42:25 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:19:55 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	print_s_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], FD);
		i++;
	}
	return (i);
}

static int	print_before_s(t_ft_printf *format)
{
	int	printed;

	printed = 0;
	while (format->width-- > 0)
	{
		ft_putchar_fd(' ', FD);
		printed++;
	}
	return (printed);
}

static int	print_after_s(t_ft_printf *format)
{
	int	printed;

	printed = 0;
	while (format->width-- > 0)
	{
		ft_putchar_fd(' ', FD);
		printed++;
	}
	return (printed);
}

static int	print_null_s(t_ft_printf *format)
{
	int	printed;

	printed = 0;
	if (format->width != 0 && format->precision > 5)
		format->width -= 6;
	if (!format->hyphen && format->width != 0)
		printed += print_before_s(format);
	if (format->precision > 5)
		printed += print_s_fd(NULL_S);
	if (format->hyphen && format->width != 0)
		printed += print_after_s(format);
	return (printed);
}

void	ftpf_format_s(t_ft_printf *format, va_list arg)
{
	int		truncated;
	char	*str;

	str = va_arg(arg, char *);
	truncated = 0;
	if (!str)
	{
		format->printed += print_null_s(format);
		return ;
	}
	if (format->precision != -1)
	{
		str = ft_substr(str, 0, format->precision);
		truncated = 1;
	}
	else if (format->precision == -1 && format->width != 0)
		format->width -= ft_strlen(str);
	if (!format->hyphen && format->width != 0)
		format->printed += print_before_s(format);
	format->printed += print_s_fd(str);
	if (format->hyphen && format->width != 0)
		format->printed += print_after_s(format);
	if (truncated == 1 && str)
		free(str);
}
//END