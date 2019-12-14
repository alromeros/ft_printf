/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:57:45 by alromero          #+#    #+#             */
/*   Updated: 2019/12/13 14:16:53 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	/*if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;*/
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > __LONG_LONG_MAX__)
			return (sign == -1 ? 0 : -1);
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * sign);
}


char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*p_s1;
	size_t	i;

	p_s1 = (char*)s1;
	i = 0;
	d = (char*)malloc(ft_strlen(p_s1) + 1);
	if (d == NULL)
		return (NULL);
	while (p_s1[i] != '\0')
	{
		d[i] = p_s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (((char*)str)[i] != '\0' && flag == 0)
	{
		if (((char*)str)[i] == c)
		{
			return ((char*)&str[i]);
			flag = 1;
		}
		i++;
	}
	if (c == '\0')
		return ((char*)&str[i]);
	return (NULL);
}
