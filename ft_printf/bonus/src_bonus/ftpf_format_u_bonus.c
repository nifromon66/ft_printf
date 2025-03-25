/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_u.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 21:18:43 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:20:06 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	print_n_u_fd(unsigned long long n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += print_n_u_fd(n / LEN_BASE_10);
	ft_putchar_fd(n % LEN_BASE_10 + 48, FD);
	i++;
	return (i);
}

static int	print_before_u(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = 0;
	if (format->width != 0 && format->precision == -1)
		format->width -= number_len;
	while (format->width-- > 0)
	{
		if (format->zero)
			ft_putchar_fd('0', FD);
		else
			ft_putchar_fd(' ', FD);
		printed++;
	}
	return (printed);
}

static int	print_middle_u(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = 0;
	if (format->precision != -1)
	{
		format->precision -= number_len;
		while (format->precision-- > 0)
		{
			ft_putchar_fd('0', FD);
			printed++;
		}
	}
	return (printed);
}

static int	print_after_u(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = 0;
	if (format->width != 0 && format->precision == -1)
		format->width -= number_len;
	while (format->width-- > 0)
	{
		if (format->zero)
			ft_putchar_fd('0', FD);
		else
			ft_putchar_fd(' ', FD);
		printed++;
	}
	return (printed);
}

void	ftpf_format_u(t_ft_printf *format, va_list arg)
{
	unsigned long long	i;
	char				*number;

	i = (unsigned long long)va_arg(arg, unsigned int);
	number = ft_ulltoa(i);
	if (!format->hyphen)
		format->printed += print_before_u(format, ((int)(ft_strlen(number))));
	format->printed += print_middle_u(format, ((int)(ft_strlen(number))));
	format->printed += print_n_u_fd(i);
	if (format->hyphen)
		format->printed += print_after_u(format, ((int)(ft_strlen(number))));
	free(number);
}

//END