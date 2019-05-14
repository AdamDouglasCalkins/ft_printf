/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:15 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/28 18:05:09 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_sign(char *sign, t_args *s, unsigned int *len, char **nbr)
{
	char	*tmp;

	if (s->sign_pos || *sign == '-')
	{
		tmp = ft_strjoin((*sign == '-') ? "-" : "+", *nbr);
		free(*nbr);
		*nbr = tmp;
		*len += 1;
	}
	else if (s->blank_pos)
	{
		tmp = ft_strjoin(" ", *nbr);
		free(*nbr);
		*nbr = tmp;
		*len += 1;
	}
}
