/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_from_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:35:11 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 16:35:59 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb)
{
	if (sarg->flag_len_modifier == 'H')
		return ((unsigned char)nb);
	else if (sarg->flag_len_modifier == 'h')
		return ((unsigned short)nb);
	else if (sarg->flag_len_modifier == 'l')
		return ((unsigned long)nb);
	else if (sarg->flag_len_modifier == 'L')
		return ((unsigned long long)nb);
	else if (sarg->flag_len_modifier == 'j')
		return (nb);
	else if (sarg->flag_len_modifier == 'z')
		return ((size_t)nb);
	else
		return ((unsigned int)nb);
}
