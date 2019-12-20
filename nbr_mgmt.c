/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:42:13 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:28:58 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_putnbr_fd(int n, int fd)
{
	long int	copia;
	int			ret;

	copia = n;
	ret = 0;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return (11);
	}
	if (copia < 0)
		copia = (copia * -1);
	if (copia > 9)
	{
		ft_putnbr_fd(copia / 10, fd);
		ft_putchar_fd((copia % 10) + '0', fd);
	}
	else
		ft_putchar_fd(copia + '0', fd);
	return (ret += digit_counter(n));
}

int		digit_counter(long int nbr)
{
	long int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		char_writter(int len, char c)
{
	int ret;

	ret = 0;
	while (len-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int		nbr_mgmt(t_printf *utils, int nbr)
{
	int			ret;
	int			dig;
	long int	len;

	ret = 0;
	dig = digit_counter(nbr);
	if (nbr < 0)
		utils->precision_len++;
	zero_dist(utils);
	len = dig < utils->precision_len ? blank_init(utils) : utils->len - dig;
	if (utils->width == 1 && utils->blank == 0)
		ret += utils->len < dig ? 0 : char_writter(len, ' ');
	if (nbr < 0)
		write(1, "-", 1);
	if (utils->precision == 1 || utils->zero == 1)
		ret += char_writter(zero_dist(utils) - digit_counter(nbr), '0');
	if (!(nbr == 0 && utils->precision == 1 && utils->precision_len == 0))
		ret += ft_putnbr_fd(nbr, 1);
	else
		ret += nbr == 0 && !utils->len ? 0 : write(1, " ", 1);
	if (utils->blank)
		ret += dig > utils->precision_len ?
		char_writter(blank_end(utils, dig) - dig, ' ') :
		char_writter(utils->len - utils->precision_len, ' ');
	return (ret);
}
