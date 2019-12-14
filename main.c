/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alromero <alromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:46:06 by alromero          #+#    #+#             */
/*   Updated: 2019/12/14 16:04:09 by alromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

int main()
{
	int   b = 54;

	//ft_printf("hola %s me llamo %d Álvaro", a, b);
	//printf("hola %     paaa Álvaro %p", c, a);
	ft_printf("hola %-10d\n", b);
	printf("hola %-10d", b);
}
