/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf.c:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 23:26:40 by nifromon  #+##+# */
/*   Updated: 2024/11/15 23:57:05 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	ftpf_percent_len(const char *s)
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

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		printed;
	int		i;

	printed = 0;
	i = -1;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (ftpf_check_spec(&format[i]) == 0)
			{
				printed += write(FD, &format[i], 1);
				continue ;
			}
			printed += ftpf_parsing(&format[i], arg);
			i += ftpf_percent_len(&format[i]);
		}
		else
			printed += write(FD, &format[i], 1);
	}
	va_end(arg);
	return (printed);
}

//END