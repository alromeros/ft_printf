/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:52:14 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 14:32:55 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	char_mgmt(t_printf *utils)
{
	if (utils->blank == 1)
		put_char_blank(utils);
	else if (utils->zero == 1)
		put_char_zero(utils);
	else
		ft_putchar_fd(va_arg(utils->ap, int), 1);
}

void	put_char_blank(t_printf *utils)
{
	int		i;
	char	cad;
	int		len;

	i = 0;
	cad = va_arg(utils->ap, int);
	ft_putchar_fd(cad, 1);
	len = utils->len - 1;
	while (len-- > 0)
		write(1, " ", 1);
}

void	put_char_zero(t_printf *utils)
{
	int i;
	int len;

	i = 0;
	len = utils->len - 1;
	while (len-- > 0)
		write(1, "0", 1);
	ft_putchar_fd(va_arg(utils->ap, int), 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
