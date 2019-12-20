/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:22:43 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:30:09 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int		ft_putstr_fixed(const char *str, int counter)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && counter != 0)
	{
		write(1, &str[i], 1);
		i++;
		counter--;
	}
	return (i);
}

int		str_blank_init(t_printf *utils, int len)
{
	int aux;

	aux = utils->precision_len < len ? utils->precision_len : len;
	aux = utils->precision == 0 ? len : aux;
	return (utils->len - aux);
}

int		str_mgmt(t_printf *utils, const char *str)
{
	int			ret;
	int			digits;
	int			len;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	digits = ft_strlen(str);
	len = str_blank_init(utils, digits);
	if (utils->precision && utils->precision_len < digits)
		digits = utils->precision_len;
	if (utils->blank == 0 && utils->width == 1)
		ret += utils->len <= digits ? 0 : char_writter(len, ' ');
	if (!(utils->precision && !utils->precision_len))
		ret += utils->precision_len ? ft_putstr_fixed(str, utils->precision_len)
		: ft_putstr(str);
	if (utils->blank)
		ret += char_writter(utils->len - digits, ' ');
	return (ret);
}
