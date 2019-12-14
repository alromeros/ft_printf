/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:08:00 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 13:34:43 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_puthex_m(unsigned int nb)
{
	if (nb >= 16)
		ft_puthex_m(nb / 16);
	nb = nb % 16;
	nb += nb < 10 ? '0' : 'a' - 10;
	write(1, &nb, 1);
}

void	ft_putpointer(unsigned long nb)
{
	write(1, "0x", 2);
	if (nb >= 16)
	ft_puthex_m(nb / 16);
	nb = nb % 16;
	nb += nb < 10 ? '0' : 'a' - 10;
	write(1, &nb, 1);
}
