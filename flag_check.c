/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:00:15 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 16:06:55 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_check(const char *format, int n)
{
	char	*flag;
	int		j;

	n++;
	j = n;
	while (format[n] == '#' || format[n] == '0' || format[n] == '-' ||
			format[n] == ' ' || format[n] == '+' || format[n] == 39 ||
			(format[n] >= '0' && format[n] <= '9') || format[n] == '*' ||
			format[n] == '.')
		n++;
	while (format[n] == 'h' || format[n] == 'l' || format[n] == 'j' ||
			format[n] == 'H' || format[n] == 'L' || format[n] == 'z')
		n++;
	flag = ft_strsub(format, j, (n - j + 1));
	return (flag);
}
