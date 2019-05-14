/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:39:15 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 18:59:23 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_i(char *flag)
{
	int	i;

	i = 0;
	while (flag[i] != '\0')
		i++;
	i--;
	return (i);
}

int		printfer(const char *format, va_list argptr)
{
	int			i;
	int			inum;
	int			result;
	char		*flag;

	i = 0;
	result = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			result++;
			i++;
		}
		else
		{
			flag = flag_check(format, i);
			inum = count_i(flag);
			result = result + inner_print(flag, inum, argptr);
			i = step_one(format, i);
		}
	}
	return (result);
}
