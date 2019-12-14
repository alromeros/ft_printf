/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:41:49 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 14:57:10 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		format_checker(const char *str, t_printf *utils)
{
	/*while (*str != 's' && *str != 'c' && *str != 'i' && *str != 'd' && *str != 'x'
	&& *str != 'X' && *str != 'u' && *str != '%' && *str != 'p')
		str++;*/
	if (*str == 's')
		str_mgmt(utils, str);
	else if (*str == 'c')
		char_mgmt(utils);
	else if (*str == 'i' || *str == 'd')
		nbr_mgmt(utils, str);
	else if (*str == 'x' || *str == 'X')
		ft_puthex_m(va_arg(utils->ap, int));
	else if (*str == 'u')
		ft_put_unsigned_fd(va_arg(utils->ap, unsigned int), 1);
	else if (*str == '%')
		write(1, "%%", 1);
	else if (*str == 'p')
	{
		ft_putpointer(va_arg(utils->ap, unsigned long));
	}
	return (0);
}
