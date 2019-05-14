/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:27:51 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 19:08:21 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_s(t_args *sarg, va_list larg)
{
	wchar_t	*ws;
	char	*s;
	size_t	len;
	size_t	len_save;

	ws = va_arg(larg, wchar_t *);
	s = (sarg->precision && sarg->precision_len) ?
		ft_nwstostr(ws, sarg->precision_len) : ft_wstostr(ws);
	s = (!s) ? ft_strdup("(null)") : ft_strdup(s);
	len = ft_strlen(s);
	free(s);
	if (sarg->precision && sarg->precision_len < len)
		len = sarg->precision_len;
	len_save = len;
	if (!sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, (sarg->zero_pad) ? '0' : ' ');
	ft_putnstr(s, len_save);
	ft_strdel((char**)&s);
	if (sarg->left_pad && (sarg->min_width > len))
		len += ft_print_pad(len, sarg->min_width, ' ');
	free(s);
	free(ws);
	return (len);
}
