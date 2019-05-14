/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:12:27 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/07 17:08:48 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_altstr(char *str, int i)
{
	int	j;

	j = i;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (j);
}

int		ft_first_x(t_args *s, char *str, size_t len, uintmax_t unb)
{
	if (!s->left_pad && (s->min_width > 1) && (s->min_width > s->precision_len))
	{
		if (s->precision_len > len)
			len += ft_print_pad(len, s->min_width - (s->precision_len - len),
					s->zero_pad ? '0' : ' ');
		else if (s->precision_len < len)
			len += ft_print_pad(len, s->min_width, s->zero_pad ? '0' : ' ');
		if (s->precision_len > ft_strlen(str))
			len += ft_print_pad(0, (s->precision_len - ft_strlen(str)),
					s->precision ? '0' : ' ');
	}
	return (len);
}

int		ft_mid_x(t_args *s, char *str, size_t len, uintmax_t unb)
{
	if (!s->left_pad && (s->min_width > 1) &&
			(s->precision_len == 0) && unb == 0)
		len += ft_print_pad(len, s->min_width, s->zero_pad ? '0' : ' ');
	if (!(s->conv_conversion == 'p') && s->precision_len > len)
		len += ft_print_pad(len, (s->precision_len - len + 2), '0');
	if (s->precision_len > len)
		len += ft_print_pad(len, 2, '0');
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0)
			|| (s->conv_conversion == 'p' && !s->zero_pad))
		ft_putstr("0x");
	if (s->alternate && s->zero_pad && !s->left_pad)
		len -= ft_altstr(str, 2);
	else
		(s->precision && !s->precision_len && unb == 0) ? 0 : ft_putstr(str);
	free(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, ' ');
	while (s->conv_conversion == 'p' && (len < (s->precision_len + 2)) &&
			!(s->min_width > 1))
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

int		ft_print_x(t_args *s, va_list larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(larg, uintmax_t));
	str = (ft_uitohex(unb, 0));
	len = (s->precision && !s->precision_len && unb == 0) ? 0 : ft_strlen(str);
	(!(s->conv_conversion == 'p' ||
		s->precision) ? put_uprecision(s, &len, &str) : 0);
	if ((s->alternate && ft_strncmp(str, "0\0", 2)) ||
			s->conv_conversion == 'p')
		len += 2;
	if ((ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0)
			|| (s->conv_conversion == 'p' && s->zero_pad))
		ft_putstr("0x");
	len = ft_first_x(s, str, len, unb);
	len = ft_mid_x(s, str, len, unb);
	return (len);
}
