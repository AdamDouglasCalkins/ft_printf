/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:40:58 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/05 17:49:30 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		let_check(char a)
{
	if (a == 'c' || a == 'C' || a == 'd' || a == 'D' ||
			a == 'i' || a == 'o' || a == 'O' || a == 'p' ||
			a == 's' || a == 'S' || a == 'u' || a == 'U' ||
			a == 'x' || a == 'X')
		return (1);
	else
		return (0);
}

int		step_one(const char *format, int i)
{
	if (format[i] == '%')
		i++;
	while ((format[i] == '#') || (format[i] == '-') || (format[i] == ' ') ||
			(format[i] == '0') || (format[i] == '+'))
		i++;
	while (((format[i] >= '0') && (format[i] <= '9')) || format[i] == '*')
		i++;
	if (format[i] == '.')
		i++;
	while (((format[i] >= '0') && (format[i] <= '9')) || format[i] == '*')
		i++;
	while ((format[i] == 'l') || (format[i] == 'h') || (format[i] == 'j') ||
			(format[i] == 'L') || (format[i] == 'H') || (format[i] == 'z'))
		i++;
	if (format[i] == '%')
		i++;
	else
	{
		if (let_check(format[i]))
			i++;
	}
	return (i);
}
