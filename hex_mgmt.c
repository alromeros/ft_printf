/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:41:39 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:22:13 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_puthex_m(unsigned int nb, char saver)
{
	if (nb >= 16)
		ft_puthex_m(nb / 16, saver);
	nb = nb % 16;
	nb += nb < 10 ? '0' : saver - 10;
	write(1, &nb, 1);
	return (0);
}

int		hex_counter(unsigned int nb)
{
	long int	num;
	int			r;
	int			ret;

	num = nb;
	ret = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		r = num % 16;
		num = num / 16;
		ret++;
	}
	return (ret);
}

int		hex_counter2(unsigned int nb, char saver)
{
	long int	num;
	int			r;
	int			ret;

	num = nb;
	ret = 0;
	ft_puthex_m(nb, saver);
	if (num == 0)
		return (1);
	while (num > 0)
	{
		r = num % 16;
		num = num / 16;
		ret++;
	}
	return (ret);
}

int		hex_mgmt(t_printf *utils, char sav, unsigned int nbr)
{
	int ret;
	int digits;
	int	len;

	ret = 0;
	digits = hex_counter(nbr);
	zero_dist(utils);
	len = digits < utils->precision_len ?
	blank_init(utils) : utils->len - digits;
	if (utils->width == 1 && utils->blank == 0)
		ret += utils->len <= digits ? 0 : char_writter(len, ' ');
	if (utils->precision == 1 || utils->zero == 1)
		ret += char_writter(zero_dist(utils) - hex_counter(nbr), '0');
	if (!(nbr == 0 && utils->precision == 1 && utils->precision_len == 0))
		ret += hex_counter2(nbr, sav);
	else
		ret += nbr == 0 && !utils->len ? 0 : write(1, " ", 1);
	if (utils->blank)
		ret += digits > utils->precision_len ?
		char_writter(blank_end(utils, digits) - digits, ' ') :
		char_writter(utils->len - utils->precision_len, ' ');
	return (ret);
}
