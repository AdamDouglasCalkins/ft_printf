/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:23:30 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/16 13:38:41 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_c(t_args *sarg, va_list larg)
{
	size_t	len;
	char	*s;

	s = ft_wctostr(va_arg(larg, wchar_t));
	len = ft_strlen(s);
	len = (len != 0) ? len : 1;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putstr(s);
	free(s);
	if (sarg->left_pad && (sarg->min_width > 1))
		len += ft_print_pad(len, sarg->min_width, ' ');
	return (len);
}
