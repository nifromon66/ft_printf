/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   print_format_p.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 19:49:57 by nifromon  #+##+# */
/*   Updated: 2024/11/15 22:19:45 by nifromon ###   ########.fr   */
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

static int	print_n_16_fd(unsigned long long n)
{
	int	tmp;
	int	i;

	i = 0;
	if ((unsigned long long)(LEN_BASE_16 - 1) < n)
		i += print_n_16_fd(n / LEN_BASE_16);
	tmp = BASE_16_LOW[(int)(n % LEN_BASE_16)];
	write(FD, &tmp, 1);
	i++;
	return (i);
}

static int	print_before_after_p(t_ft_printf *format)
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

static int	print_null_p(t_ft_printf *format)
{
	int	printed;

	printed = 0;
	if (format->width != 0)
		format->width -= 5;
	if (!format->hyphen && format->width != 0)
		printed += print_before_after_p(format);
	printed += print_s_fd(NULL_P);
	if (format->hyphen && format->width != 0)
		printed += print_before_after_p(format);
	return (printed);
}

void	ftpf_format_p(t_ft_printf *format, va_list arg)
{
	unsigned long long	p;

	p = va_arg(arg, unsigned long long);
	if (!p)
		return ((void)(format->printed += print_null_p(format)));
	format->width -= ft_ptrlen(p);
	format->width -= 2;
	if (!format->hyphen && format->width != 0)
		format->printed += print_before_after_p(format);
	ft_putstr_fd("0x", FD);
	format->printed += (print_n_16_fd(p) + LEN_OX);
	if (format->hyphen && format->width != 0)
		format->printed += print_before_after_p(format);
}

//END