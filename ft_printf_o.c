/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:02:34 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/07 16:13:32 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_num(char flag, t_args *sarg, va_list larg)
{
	uintmax_t	nb;

	if (flag == 'O')
		nb = (unsigned long)(va_arg(larg, unsigned long int));
	else
		nb = ft_unsigned_from_lenght(sarg, va_arg(larg, uintmax_t));
	return (nb);
}

int			ft_print_o(char flag, t_args *sarg, va_list larg)
{
	char		*str;
	size_t		len;
	uintmax_t	nb;

	nb = get_num(flag, sarg, larg);
	str = ft_uitooctal(nb, (sarg->alternate && nb != 0) ? 1 : 0);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
	if (!sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, sarg->zero_pad ? '0' : ' ');
	if (sarg->precision && !sarg->precision_len && nb == 0 && !sarg->alternate)
		if (sarg->min_width)
		{
			len = sarg->min_width;
			ft_putchar(' ');
		}
		else
			len = 0;
	else
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
