/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:47:35 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 19:08:06 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_uimtoa(uintmax_t num)
{
	char		*str;
	int			i;
	uintmax_t	numtmp;

	if (!(str = ft_strnew(ft_countdigit_unsigned(num) + 1)))
		return (NULL);
	numtmp = num;
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (numtmp > 0)
	{
		str[i++] = '0' + (numtmp % 10);
		numtmp /= 10;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
