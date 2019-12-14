/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:42:13 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 14:36:11 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	put_nbr_zero(t_printf *utils, const char *c)
{
	int			copia;
	int			len;

	copia = va_arg(utils->ap, int);
	len = (utils->len) - digit_counter(copia);
	if (copia < 0)
	{
		copia = (copia * -1);
		write(1, "-", 1);
		len--;
	}
	while (len-- > 0)
		write(1, "0", 1);
	ft_putnbr_fd(copia, 1);
	ft_strlen(c);
}

void	put_nbr_blank(t_printf *utils, const char *c)
{
	int			copia;
	int			len;

	copia = va_arg(utils->ap, int);
	len = (utils->len) - digit_counter(copia);
	if (copia < 0)
	{
		copia = (copia * -1);
		write(1, "-", 1);
		len--;
	}
	ft_putnbr_fd(copia, 1);
	while (len-- > 0)
		write(1, " ", 1);
	ft_strlen(c);
}

int		digit_counter(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	nbr_mgmt(t_printf *utils, const char *c)
{
	if (utils->blank == 1)
		put_nbr_blank(utils, c);
	else if (utils->zero == 1)
		put_nbr_zero(utils, c);
	else
		ft_putnbr_fd(va_arg(utils->ap, int), 1);		
}
