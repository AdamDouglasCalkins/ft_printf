/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:20:59 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/16 13:41:10 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_args *sarg, va_list larg)
{
	size_t	len;

	if (sarg->flag_len_modifier == 'l')
		return (ft_print_upper_c(sarg, larg));
	else
	{
		len = 1;
		if (!sarg->left_pad && (sarg->min_width > len))
			len += ft_print_pad(len, sarg->min_width,
					(sarg->zero_pad) ? '0' : ' ');
		ft_putchar(va_arg(larg, int));
		if (sarg->left_pad && (sarg->min_width > 1))
			len += ft_print_pad(len, sarg->min_width, ' ');
		return (len);
	}
}
