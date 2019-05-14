/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_from_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:32:07 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 16:33:58 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_signed_from_lenght(t_args *sarg, intmax_t nb)
{
	if (sarg->flag_len_modifier == 'h')
		return ((short)nb);
	else if (sarg->flag_len_modifier == 'H')
		return ((signed char)nb);
	else if (sarg->flag_len_modifier == 'l')
		return ((long)nb);
	else if (sarg->flag_len_modifier == 'L')
		return ((long long)nb);
	else if (sarg->flag_len_modifier == 'j')
		return (nb);
	else if (sarg->flag_len_modifier == 'z')
		return ((size_t)nb);
	else
		return ((int)nb);
}
