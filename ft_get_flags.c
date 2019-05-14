/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:58:52 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/16 13:52:38 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flags(char *flag, t_args *sarg, int n)
{
	if (flag[n] == '#' || flag[n] == '0' || flag[n] == '-'
		|| flag[n] == ' ' || flag[n] == '+' || flag[n] == 39)
	{
		if (flag[n] == '#')
			sarg->alternate = 1;
		else if (flag[n] == '0')
			sarg->zero_pad = 1;
		else if (flag[n] == '-')
			sarg->left_pad = 1;
		else if (flag[n] == ' ')
			sarg->blank_pos = 1;
		else if (flag[n] == '+')
		{
			sarg->sign_pos = 1;
			sarg->blank_pos = 0;
		}
		n++;
	}
	return (n);
}
