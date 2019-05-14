/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:55:21 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/07 16:12:09 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decide_width(int i, t_args *sarg, va_list argptr)
{
	if (i < 0)
	{
		sarg->min_width = (i * -1);
		sarg->left_pad = 1;
	}
	else
		sarg->min_width = i;
}

int		ft_get_width(char *flag, t_args *sarg, va_list argptr, int n)
{
	int	i;

	if (flag[n] == '*' || ft_isdigit(flag[n]))
	{
		if (ft_isdigit(flag[n]))
		{
			while (ft_isdigit(flag[n]))
			{
				sarg->min_width = ((sarg->min_width) * 10) + ((flag[n]) - '0');
				n++;
			}
		}
		else
		{
			i = va_arg(argptr, int);
			ft_decide_width(i, sarg, argptr);
			n++;
		}
	}
	return (n);
}
