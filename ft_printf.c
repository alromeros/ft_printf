/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:15:47 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 15:46:26 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	int				i;
	t_printf		utils;

	i = 0;
	va_start(utils.ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			flag_checker(&str[++i], &utils);
			while (!(ft_strchr("cspdiuxX%%", str[i])))
				i++;
			format_checker(&str[i], &utils);
		}
		i++;
	}
	va_end(utils.ap);
	return (0);
}
