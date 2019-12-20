/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:08:00 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:25:12 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_putpointer(unsigned long nb)
{
	if (nb != 0)
	{
		if (nb >= 16)
			ft_putpointer(nb / 16);
		nb = nb % 16;
		nb += nb < 10 ? '0' : 'a' - 10;
		write(1, &nb, 1);
	}
	return (0);
}

int		mem_count(unsigned long nbr)
{
	unsigned long	num;
	int				r;
	int				ret;

	num = nbr;
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

int		mem_mgmt(t_printf *utils, unsigned long nbr)
{
	int ret;
	int dig;
	int	len;

	ret = 0;
	dig = mem_count(nbr) + 2;
	dig = utils->precision && utils->precision_len == 0
	&& nbr == 0 ? dig - 1 : dig;
	zero_dist(utils);
	len = dig < utils->precision_len ? blank_init(utils) : utils->len - dig;
	if (utils->width == 1 && utils->blank == 0)
		ret += utils->len <= dig ? 0 : char_writter(len, ' ');
	ret += write(1, "0x", 2);
	if (utils->precision == 1 || utils->zero == 1)
		ret += char_writter(zero_dist(utils) - mem_count(nbr), '0');
	if (!(utils->precision && !utils->precision_len))
	{
		ret += dig - 2;
		nbr != 0 ? ft_putpointer(nbr) : write(1, "0", 1);
	}
	if (utils->blank)
		ret += dig > utils->precision_len ?
		char_writter(blank_end(utils, dig) - dig, ' ') :
		char_writter(utils->len - utils->precision_len, ' ');
	return (ret);
}
