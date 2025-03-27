/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_x_upp.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 22:03:37 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:20:32 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

static int	print_n_16_fd_upp(unsigned long long n)
{
	int	tmp;
	int	i;

	i = 0;
	if ((unsigned long long)(LEN_BASE_16 - 1) < n)
		i += print_n_16_fd_upp(n / LEN_BASE_16);
	tmp = BASE_16_UPP[(int)(n % LEN_BASE_16)];
	write(FD, &tmp, 1);
	i++;
	return (i);
}

static int	print_before_x_upp(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = format->hashtag;
	if (format->hashtag == 2)
		format->width -= 2;
	if (format->precision == -1)
		format->width -= number_len;
	if (format->hashtag == 2 && format->zero)
		ft_putstr_fd("0X", FD);
	while (format->width-- > 0)
	{
		if (format->zero)
			ft_putchar_fd('0', FD);
		else
			ft_putchar_fd(' ', FD);
		printed++;
	}
	if (format->hashtag == 2 && !format->zero)
		ft_putstr_fd("0X", FD);
	return (printed);
}

static int	print_middle_x_upp(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = format->hashtag;
	if (format->hyphen && format->hashtag == 2)
		ft_putstr_fd("0X", FD);
	else if (format->hashtag == 2 && format->width == 0)
		ft_putstr_fd("0X", FD);
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

static int	print_after_x_upp(t_ft_printf *format, int number_len)
{
	int	printed;

	printed = format->hashtag;
	if (format->hashtag == 2)
		format->width -= 2;
	if (format->precision == -1)
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

void	ftpf_format_x_upp(t_ft_printf *format, va_list arg)
{
	unsigned long long	x_upp;

	x_upp = va_arg(arg, unsigned int);
	if (x_upp == 0)
		format->hashtag = 0;
	if (!format->hyphen && format->width != 0)
		format->printed += print_before_x_upp(format, ft_ptrlen(x_upp));
	format->printed += print_middle_x_upp(format, ft_ptrlen(x_upp));
	if (format->precision == 0)
	{
		if (x_upp != 0)
			format->printed += print_n_16_fd_upp(x_upp);
	}
	else
		format->printed += print_n_16_fd_upp(x_upp);
	if (format->hyphen && format->width != 0)
		format->printed += print_after_x_upp(format, ft_ptrlen(x_upp));
}

//END