/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:15:47 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:21:14 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	int				i;
	t_printf		utils;
	int				ret;

	i = 0;
	ret = 0;
	va_start(utils.ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret += write(1, &str[i], 1);
		else if (str[i] == '%')
		{
			flag_checker(&str[++i], &utils);
			while (str[i] != '\0' && !(ft_strchr("cspdiuxX%%", str[i])))
				i++;
			if (str[i] != '\0')
				ret += format_checker(&str[i], &utils);
		}
		if (str[i] != '\0')
			i++;
	}
	va_end(utils.ap);
	return (ret);
}
