/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:52:14 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:42:37 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		char_mgmt(t_printf *utils, int c)
{
	int ret;
	int digits;
	int	len;

	ret = 0;
	digits = 1;
	zero_dist(utils);
	len = digits < utils->precision_len ?
	blank_init(utils) : utils->len - digits;
	if (utils->width == 1 && utils->blank == 0)
		ret += utils->len <= digits ? 0 : char_writter(len, ' ');
	if (utils->precision == 1 || utils->zero == 1)
		ret += char_writter(zero_dist(utils) - 1, '0');
	if (!(utils->precision && !utils->precision_len))
		ret += write(1, &c, 1);
	if (utils->blank)
		ret += digits > utils->precision_len ?
		char_writter(blank_end(utils, digits) - digits, ' ') :
		char_writter(utils->len - utils->precision_len, ' ');
	return (ret);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
