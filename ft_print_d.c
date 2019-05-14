/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:04:03 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/07 16:14:46 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_d(char flag, t_args *sarg, va_list larg)
{
	char		*str;
	char		sign;
	unsigned	len;

	str = ft_get_nbstr(flag, sarg, larg, &sign);
	len = ft_strlen(str);
	put_precision(sarg, &len, &str, &sign);
	put_sign(&sign, sarg, &len, &str);
	if (sarg->blank_pos && sarg->precision_len && sarg->precision_len <= len)
		str[0] = '0';
	if (!sarg->left_pad && sarg->precision_len < sarg->min_width &&
			sarg->min_width > len)
		len += ft_print_pad(len, sarg->min_width, ' ');
	if (!(!ft_strcmp(str, "0") && sarg->precision &&
				sarg->precision_len <= len))
		ft_putstr(str);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(str);
	return (len);
}
