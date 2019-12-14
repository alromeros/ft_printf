/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:40:15 by alromero          #+#    #+#             */
/*   Updated: 2019/12/13 18:16:52 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		flag_checker(const char *c, t_printf *utils)
{	
	if (!(ft_strchr("-*.0123456789", *c)))
		return (0);
	while (ft_strchr("-*.0123456789", *c))
	{
		if (*c == '*')
			return (0);
		else if (*c == '-')
			utils->blank = 1;
		else if (*c == '0')
			utils->zero = 1;
		else if (*c == '.')
			utils->width = 1;
		else if (*c >= '0' && *c <= '9')
		{ 
			utils->len = ft_atoi(c);
			while (*c >= '0' && *c <= '9')
				c++;
			c--;
		}
		c++;
	}
	return (0);
}

/*if (*c == 's' || *c == 'c' || *c == 'i' || *c == 'd' || *c == 'x'
|| *c == 'X' || *c == 'u' || *c == '%' || *c == 'p')
	return (format_checker(&(*c), ap));*/