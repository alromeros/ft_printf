/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:45:41 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 15:54:34 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

void				hex_calculator(int num);
void				ft_putstr(const char *str);
void				ft_rev_int_tab(char *tab, int size);
char				*ft_calc(int flag, int nbr, char *base);
int					detector_base(char *str);
long	int			is_negative(long int nbr);
void				ft_putnbr_base(int nbr, char *base);
void				ft_put_unsigned_fd(unsigned int n, int fd);
typedef struct		s_printf
{
	int		zero;
	int		blank;
	va_list ap;
	int 	width;
	int		len;
}					t_printf;
int		flag_checker(const char *c, t_printf *utils);
int		format_checker(const char *str, t_printf *utils);
void	left_justifier(const char *c, t_printf *utils);
void	zero_justifier(const char *c, t_printf *utils);
void	ft_putchar(char c);
void	nbr_mgmt(t_printf *utils, const char *c);
void	put_nbr_zero(t_printf *utils, const char *c);
int		digit_counter(int nbr);
void	put_nbr_blank(t_printf *utils, const char *c);
void	ft_putpointer(unsigned long nb);
void	ft_puthex_m(unsigned int nb);
void	char_mgmt(t_printf *utils);
void	put_char_blank(t_printf *utils);
void	put_char_zero(t_printf *utils);
void	str_mgmt(t_printf *utils, const char *c);
void	ft_putpointer(unsigned long nb);
void	ft_puthex_m(unsigned int nb);
int		ft_printf(const char *str, ...);

#endif
