/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   init.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 23:00:21 by nifromon  #+##+# */
/*   Updated: 2024/11/15 23:24:52 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers_bonus/ft_printf_bonus.h"

t_ft_printf	*ftpf_init_struct(void)
{
	t_ft_printf	*format;

	format = (t_ft_printf *)malloc(sizeof(t_ft_printf));
	if (!format)
		return (NULL);
	format->hashtag = 0;
	format->zero = 0;
	format->hyphen = 0;
	format->blank = 0;
	format->plus = 0;
	format->width = 0;
	format->precision = -1;
	format->star = 0;
	format->specifier = 0;
	format->printed = 0;
	return (format);
}

//END