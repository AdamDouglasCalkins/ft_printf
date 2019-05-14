/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:06:39 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 18:00:46 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_precision(t_args *s, unsigned int *len, char **nbr, char *sign)
{
	char			*tmp;
	unsigned int	l;
	unsigned int	i;
	unsigned int	w;

	i = 0;
	if ((s->precision_len > *len) ||
			(s->zero_pad && s->min_width > *len && !s->left_pad))
	{
		w = (s->precision_len) ? s->precision_len : s->min_width;
		l = (s->precision) ? s->precision_len - *len : s->min_width - *len;
		if (s->zero_pad && !s->precision)
			l -= (*sign == '-' || s->sign_pos) ? 1 : 0;
		tmp = ft_strnew((s->precision_len) ? s->precision_len : s->min_width);
		if (*sign == '+' && s->blank_pos)
			l--;
		while (i < l)
			tmp[i++] = '0';
		l = 0;
		while (i < w)
			tmp[i++] = nbr[0][l++];
		free(*nbr);
		*nbr = tmp;
		*len = ft_strlen(tmp);
	}
}
