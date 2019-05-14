/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:17:44 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 18:15:56 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_altstr1(char *str, int i)
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

int		ft_print_upper_x(t_args *s, va_list larg)
{
	char		*str;
	size_t		len;
	uintmax_t	unb;

	unb = ft_unsigned_from_lenght(s, va_arg(larg, uintmax_t));
	str = (ft_uitohex(unb, 1));
	len = (s->precision && !s->precision_len && unb == 0) ? 0 : ft_strlen(str);
	put_uprecision(s, &len, &str);
	if (s->alternate && ft_strncmp(str, "0\0", 2))
		len += 2;
	if (ft_strncmp(str, "0\0", 2) && s->alternate && s->zero_pad && unb > 0)
		ft_putstr("0X");
	if (!s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, s->zero_pad ? '0' : ' ');
	if (ft_strncmp(str, "0\0", 2) && s->alternate && !s->zero_pad && unb > 0)
		ft_putstr("0X");
	if (s->alternate && s->zero_pad && !s->left_pad)
		len -= ft_altstr1(str, 2);
	else
		(s->precision && !s->precision_len && unb == 0) ? 0 : ft_putstr(str);
	if (s->left_pad && (s->min_width > 1))
		len += ft_print_pad(len, s->min_width, ' ');
	free(str);
	return (len);
}
