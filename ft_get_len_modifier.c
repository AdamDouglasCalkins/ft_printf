/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_modifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:51:25 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 18:56:08 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len_modifier(char *flag, t_args *sarg, int n)
{
	if (flag[n] == 'h' && flag[n + 1] == 'h')
	{
		sarg->flag_len_modifier = 'H';
		n = n + 2;
	}
	else if (flag[n] == 'l' && flag[n + 1] == 'l')
	{
		sarg->flag_len_modifier = 'L';
		n = n + 2;
	}
	else if (flag[n] == 'h')
		sarg->flag_len_modifier = 'h';
	else if (flag[n] == 'l')
		sarg->flag_len_modifier = 'l';
	else if (flag[n] == 'j')
		sarg->flag_len_modifier = 'j';
	else if (flag[n] == 'z')
		sarg->flag_len_modifier = 'z';
	else
		return (n);
	if (flag[n + 1] == 'D' || flag[n + 1] == 'O' || flag[n + 1] == 'U')
		sarg->flag_len_modifier = 'l';
	n++;
	return (n);
}
