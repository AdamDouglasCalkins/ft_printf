/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:14:46 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 17:15:36 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = ft_memalloc(++size)))
	{
		i = 0;
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
