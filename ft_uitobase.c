/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:07:10 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 17:08:03 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitobase(uintmax_t nb, unsigned int base)
{
	char		*ret;
	uintmax_t	rst;
	int			i;

	ret = ft_strnew(65);
	i = 0;
	if (nb == 0)
		ret[i] = '0';
	while (nb > 0)
	{
		rst = nb % base;
		nb /= base;
		ret[i] = rst + '0';
		i++;
	}
	ft_strrev(ret);
	return (ret);
}
