/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_d.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 18:40:38 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:19:08 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	print_n_10_fd(long n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd(INT_MIN_S, FD);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', FD);
		i++;
	}
	if (n > 9)
		i += print_n_10_fd(n / LEN_BASE_10);
	ft_putchar_fd(n % LEN_BASE_10 + 48, FD);
	i++;
	return (i);
}

static int	print_before_d(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = format->blank;
	printed += format->plus;
	if (format->width != 0 && format->precision == -1)
		format->width -= number_len;
	if ((format->blank || format->plus) && format->width != 0)
		format->width--;
	if (format->plus && format->zero)
		ft_putchar_fd('+', FD);
	else if (format->blank && format->zero)
		ft_putchar_fd(' ', FD);
	while (format->width-- > 0)
	{
		if (format->zero)
			ft_putchar_fd('0', FD);
		else
			ft_putchar_fd(' ', FD);
		printed++;
	}
	if (format->plus && !format->zero)
		ft_putchar_fd('+', FD);
	else if (format->blank && !format->zero)
		ft_putchar_fd(' ', FD);
	return (printed);
}

static int	print_middle_d(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = 0;
	if (format->hyphen && (format->blank || format->plus))
	{
		if (format->blank)
			ft_putchar_fd(' ', FD);
		else if (format->plus)
			ft_putchar_fd('+', FD);
		printed++;
	}
	if (format->precision > 0)
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

static int	print_after_d(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = 0;
	if (format->width != 0 && format->precision == -1)
		format->width -= number_len;
	if ((format->blank || format->plus) && format->width != 0)
		format->width--;
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

void	ftpf_format_d(t_ft_printf *format, va_list arg)
{
	long	i;
	char	*number;

	i = (long)va_arg(arg, int);
	if ((i < 0))
	{
		format->blank = 0;
		format->plus = 0;
		if (!format->hyphen && (format->zero || format->precision != -1))
		{
			format->printed += write(FD, "-", 1);
			i *= -1;
			if (format->width != 0)
				format->width--;
		}
	}
	number = ft_itoa((int)i);
	if (!format->hyphen)
		format->printed += print_before_d(format, ((int)(ft_strlen(number))));
	format->printed += print_middle_d(format, ((int)(ft_strlen(number))));
	if (format->precision == 0)
	{
		if (i != 0)
			format->printed += print_n_10_fd(i);
	}
	else
		format->printed += print_n_10_fd(i);
	if (format->hyphen)
		format->printed += print_after_d(format, ((int)(ft_strlen(number))));
	free(number);
}

//END