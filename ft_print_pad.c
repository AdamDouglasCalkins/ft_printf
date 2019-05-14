/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:24:49 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 17:25:08 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_pad(int len_res, int pad, char c)
{
	int i;

	i = 0;
	while (pad > len_res)
	{
		ft_putchar(c);
		pad--;
		i++;
	}
	return (i);
}
