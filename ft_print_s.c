/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:25:31 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 18:18:45 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(t_args *sarg, va_list larg)
{
	char	*s;
	size_t	len;
	size_t	len_save;

	if (sarg->flag_len_modifier == 'l')
		return (ft_print_upper_s(sarg, larg));
	s = va_arg(larg, char *);
	s = (!s) ? ft_strdup("(null)") : ft_strdup(s);
	len = ft_strlen(s);
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
	return (len);
}
