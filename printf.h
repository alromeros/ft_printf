/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:45:41 by alromero          #+#    #+#             */
/*   Updated: 2019/12/20 18:59:17 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_printf
{
	int		zero;
	int		blank;
	va_list ap;
	int		precision;
	int		width;
	int		len;
	int		precision_len;
	int		arg;
	int		arg_len;
}					t_printf;
int					char_mgmt(t_printf *utils, int c);
void				utils_init(t_printf *utils);
void				flag_checker(const char *c, t_printf *utils);
int					format_checker(const char *str, t_printf *utils);
void				arg_arg(t_printf *utils, const char *str);
int					zero_dist(t_printf *utils);
int					blank_init(t_printf *utils);
int					blank_end(t_printf *utils, int len);
int					ft_printf(const char *str, ...);
int					ft_puthex_m(unsigned int nb, char saver);
int					hex_counter(unsigned int nb);
int					hex_counter2(unsigned int nb, char saver);
int					hex_mgmt(t_printf *utils, char sav, unsigned int nbr);
int					ft_putpointer(unsigned long nb);
int					mem_count(unsigned long nbr);
int					mem_mgmt(t_printf *utils, unsigned long nbr);
int					digit_counter(long int nbr);
int					ft_putnbr_fd(int n, int fd);
int					char_writter(int len, char c);
int					nbr_mgmt(t_printf *utils, int nbr);
int					ft_putstr(const char *str);
int					ft_putstr_fixed(const char *str, int counter);
int					str_blank_init(t_printf *utils, int len);
int					str_mgmt(t_printf *utils, const char *str);
int					unsigned_mgmt(t_printf *utils, unsigned long int nbr);
int					ft_putunsigned_fd(unsigned long int n, int fd);

#endif
