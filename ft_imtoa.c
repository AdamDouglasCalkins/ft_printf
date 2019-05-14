/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:50:23 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 19:07:39 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_imtoa(intmax_t num)
{
	char		*str;
	int			sign;
	int			i;
	intmax_t	numtmp;

	if (!(str = ft_strnew(ft_countdigit(num))))
		return (NULL);
	numtmp = num;
	if ((sign = (num < 0)))
		numtmp = -num;
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (numtmp > 0)
	{
		str[i++] = '0' + (numtmp % 10);
		numtmp /= 10;
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
