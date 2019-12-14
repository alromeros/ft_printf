/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:41:39 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 13:44:15 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	nbr_mgmt(t_printf *utils, const char *c)
{
	if (utils->blank == 1)
		put_nbr_blank(utils, c);
	else if (utils->zero == 1)
		put_nbr_zero(utils, c);
	else
		ft_puthex_m(va_arg(utils->ap, int));		
}
