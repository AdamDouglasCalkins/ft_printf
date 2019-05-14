/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:14:12 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 19:07:56 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_per(t_args *sarg)
{
	size_t	len;

	len = 1;
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putchar('%');
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}
