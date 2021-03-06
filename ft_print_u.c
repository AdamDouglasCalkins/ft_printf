/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:29:47 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/06 19:25:50 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_u(char flag, t_args *sarg, va_list larg)
{
	char		*str;
	size_t		len;
	uintmax_t	nb;

	if (flag == 'U')
		nb = (unsigned long)(va_arg(larg, unsigned long int));
	else
		nb = ft_unsigned_from_lenght(sarg, va_arg(larg, uintmax_t));
	if (nb == 0 && sarg->precision)
		str = ft_strnew(0);
	else
		str = ft_uimtoa(nb);
	len = ft_strlen(str);
	put_uprecision(sarg, &len, &str);
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
