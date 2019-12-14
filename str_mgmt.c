/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mgmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:22:43 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 14:36:42 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	put_str_blank(t_printf *utils, const char *str)
{
	int		i;
	char	*cad;
	int		len;

	i = 0;
	cad = va_arg(utils->ap, char *);
	while (cad[i] != '\0')
	{
		write(1, &cad[i], 1);
		i++;
	}
	len = utils->len - ft_strlen(cad);
	while (len-- > 0)
		write(1, " ", 1);
	ft_strlen(str);
}

void	put_str_zero(t_printf *utils, const char *str)
{
	int i;
	int len;

	i = 0;
	len = utils->len - ft_strlen(va_arg((utils->ap), char *));
	while (len-- > 0)
		write(1, "0", 1);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	ft_strlen(str);
}

void	str_mgmt(t_printf *utils, const char *c)
{
	if (utils->blank == 1)
		put_str_blank(utils, c);
	else if (utils->zero == 1)
		put_str_zero(utils, c);
	else
		ft_putstr(va_arg(utils->ap, char *));		
}
