/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:47:44 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/05 17:29:52 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(t_args *sarg, va_list larg)
{
	sarg->alternate = 1;
	sarg->flag_len_modifier = 'l';
	sarg->conv_conversion = 'p';
	return (ft_print_x(sarg, larg));
}
