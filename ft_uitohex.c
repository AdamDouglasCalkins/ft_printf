/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:41:33 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 18:33:26 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitohex(uintmax_t nb, int uppercase)
{
	char	*nbbase;
	char	*ret;
	char	hex[16];
	int		i;

	ret = ft_strnew(16);
	if (uppercase)
		ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	nbbase = ft_uitobase(nb, 16);
	i = 0;
	while (nbbase[i] != '\0')
	{
		ret[i] = hex[(int)nbbase[i] - '0'];
		i++;
	}
	free(nbbase);
	return (ret);
}
