/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitooctal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:05:29 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 17:06:40 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitooctal(uintmax_t nb, int prefix)
{
	char	*nbbase;
	char	*ret;
	int		i;

	nbbase = ft_uitobase(nb, 8);
	if (!prefix)
		return (nbbase);
	ret = ft_strnew(prefix + ft_strlen(nbbase));
	ret[0] = (prefix) ? '0' : 0;
	i = 0;
	while (nbbase[i] != '\0')
	{
		ret[i + 1] = nbbase[i];
		i++;
	}
	free(nbbase);
	return (ret);
}
