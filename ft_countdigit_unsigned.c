/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:02:51 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 18:45:47 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countdigit_unsigned(uintmax_t num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
