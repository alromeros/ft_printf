/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:41:49 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:45:01 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		format_checker(const char *str, t_printf *utils)
{
	int ret;

	ret = 0;
	if (*str == 's')
		ret += str_mgmt(utils, va_arg(utils->ap, const char *));
	else if (*str == 'c')
		ret += char_mgmt(utils, va_arg(utils->ap, int));
	else if (*str == 'i' || *str == 'd')
		ret += nbr_mgmt(utils, va_arg(utils->ap, int));
	else if (*str == 'x')
		ret += hex_mgmt(utils, 'a', va_arg(utils->ap, unsigned int));
	else if (*str == 'X')
		ret += hex_mgmt(utils, 'A', va_arg(utils->ap, unsigned int));
	else if (*str == 'u')
		ret += unsigned_mgmt(utils, va_arg(utils->ap, unsigned int));
	else if (*str == '%')
		ret += char_mgmt(utils, '%');
	else if (*str == 'p')
		ret += mem_mgmt(utils, va_arg(utils->ap, unsigned long int));
	return (ret);
}

void	arg_arg(t_printf *utils, const char *str)
{
	ft_strlen(str);
	if (!(utils->precision))
	{
		if (!utils->zero)
			utils->width = 1;
		utils->len = va_arg(utils->ap, int);
		if (utils->len < 0)
		{
			utils->blank = 1;
			utils->len = (utils->len * -1);
		}
	}
	else
	{
		utils->precision_len = va_arg(utils->ap, int);
		if (utils->precision_len < 0)
		{
			utils->precision_len = 0;
			utils->precision = 0;
		}
	}
}

int		zero_dist(t_printf *utils)
{
	if (utils->zero && utils->blank && utils->precision)
	{
		utils->width = 0;
		utils->zero = 0;
	}
	if (utils->zero && utils->precision)
	{
		utils->width = 1;
		if (utils->zero > utils->precision)
		{
			utils->precision = 0;
			return (utils->len);
		}
		else
			return (utils->precision_len);
	}
	if (utils->zero && !utils->precision && !utils->blank)
		return (utils->len);
	else if (utils->precision && !utils->zero)
		return (utils->precision_len);
	return (0);
}

int		blank_init(t_printf *utils)
{
	if (utils->width)
	{
		if (utils->precision && (utils->precision_len <= utils->len))
			return (utils->len - utils->precision_len);
		else if (utils->width && !utils->precision)
			return (utils->len);
		else if (utils->width && utils->precision_len > utils->len)
			return (0);
	}
	return (0);
}

int		blank_end(t_printf *utils, int len)
{
	if (utils->blank)
	{
		if (utils->precision)
		{
			if (utils->precision_len >= utils->len)
				return (0);
			else if (utils->precision_len > len)
				return (utils->len - utils->precision_len);
			else if (utils->precision_len < len)
				return (utils->len);
		}
		else
			return (utils->len);
	}
	return (0);
}
