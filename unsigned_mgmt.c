/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_mgmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:45:14 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:31:31 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		unsigned_mgmt(t_printf *utils, unsigned long int nbr)
{
	int ret;
	int dig;
	int	len;

	ret = 0;
	dig = digit_counter(nbr);
	if (nbr < 0)
		utils->precision_len++;
	zero_dist(utils);
	len = dig < utils->precision_len ? blank_init(utils) : utils->len - dig;
	if (utils->width == 1 && utils->blank == 0)
		ret += utils->len <= dig ? 0 : char_writter(len, ' ');
	if (nbr < 0)
		write(1, "-", 1);
	if (utils->precision == 1 || utils->zero == 1)
		ret += char_writter(zero_dist(utils) - digit_counter(nbr), '0');
	if (!(nbr == 0 && utils->precision == 1 && utils->precision_len == 0))
		ret += ft_putunsigned_fd(nbr, 1);
	else
		ret += nbr == 0 && !utils->len ? 0 : write(1, " ", 1);
	if (utils->blank)
		ret += dig > utils->precision_len ?
		char_writter(blank_end(utils, dig) - dig, ' ') :
		char_writter(utils->len - utils->precision_len, ' ');
	return (ret);
}

int		ft_putunsigned_fd(unsigned long int n, int fd)
{
	long int	copia;
	int			ret;

	copia = n;
	ret = 0;
	if (copia > 9)
	{
		ft_putnbr_fd(copia / 10, fd);
		ft_putchar_fd((copia % 10) + '0', fd);
	}
	else
		ft_putchar_fd(copia + '0', fd);
	return (ret += digit_counter(n));
}
