/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uprecision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:11:28 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 13:21:17 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_uprecision(t_args *s, size_t *len, char **nbr)
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
		tmp = ft_strnew((s->precision_len) ? s->precision_len : s->min_width);
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
