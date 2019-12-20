/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:40:15 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:54:54 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	utils_init(t_printf *utils)
{
	utils->precision = 0;
	utils->zero = 0;
	utils->width = 0;
	utils->blank = 0;
	utils->len = 0;
	utils->precision_len = 0;
	utils->arg = 0;
	utils->arg_len = 0;
}

void	flag_checker(const char *c, t_printf *utils)
{
	utils_init(utils);
	while (ft_strchr("-*.0123456789", *c))
	{
		if (*c == '*')
			arg_arg(utils, &(*c));
		else if (*c == '-')
			utils->blank = 1;
		else if (*c == '0' && *(c - 1) != '.')
			utils->zero = 1;
		else if (*c == '.')
			utils->precision = 1;
		else if ((*c >= '0' && *c <= '9'))
		{
			if (*(c - 1) != '.')
			{
				(utils->len) = ft_atoi(c);
				utils->width = (*(c - 1) == '%') ? 1 : 0;
			}
			else
				(utils->precision_len) = ft_atoi(c);
			while (*c >= '0' && *c <= '9' && ft_isdigit(*(c + 1)))
				c++;
		}
		c++;
	}
}
