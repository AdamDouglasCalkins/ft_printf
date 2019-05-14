/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:36:15 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 14:53:41 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			result;

	result = 0;
	if (!format)
	{
		ft_putstr("ft_printf: Must be given  valid format string");
		return (result);
	}
	va_start(argptr, format);
	result = printfer(format, argptr);
	va_end(argptr);
	return (result);
}
