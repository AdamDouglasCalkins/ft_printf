/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:48:42 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/06 17:13:01 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_args(char *flag, va_list argptr, t_args *sarg)
{
	int		n;

	n = 0;
	while (flag[n] == '#' || flag[n] == '0' || flag[n] == '-'
		|| flag[n] == ' ' || flag[n] == '+' || flag[n] == 39)
		n = ft_get_flags(flag, sarg, n);
	if ((flag[n] >= '0' && flag[n] <= '9') || flag[n] == '*')
		n = ft_get_width(flag, sarg, argptr, n);
	if (flag[n] == '.')
	{
		n++;
		n = ft_get_precision(flag, sarg, argptr, n);
	}
	if (flag[n] == 'l' || flag[n] == 'h' || flag[n] == 'j'
		|| flag[n] == 'z' || flag[n] == 'H' || flag[n] == 'L')
		n = ft_get_len_modifier(flag, sarg, n);
	if (flag[n] == 'D' || flag[n] == 'O' || flag[n] == 'U')
		sarg->flag_len_modifier = 'l';
}
