/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_c.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 18:23:29 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:18:55 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	print_c_fd(char c)
{
	return (write(FD, &c, 1));
}

static int	print_before_c(t_ft_printf *format)
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

static int	print_after_c(t_ft_printf *format)
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

void	ftpf_format_c(t_ft_printf *format, va_list arg)
{
	int	c;

	c = va_arg(arg, int);
	if (format->width != 0)
		format->width--;
	if (!format->hyphen && format->width != 0)
		format->printed += print_before_c(format);
	format->printed += print_c_fd(c);
	if (format->hyphen && format->width != 0)
		format->printed += print_after_c(format);
}

//END