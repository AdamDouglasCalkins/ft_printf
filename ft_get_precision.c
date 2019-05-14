/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:59 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 18:57:28 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_precision(char *flag, t_args *sarg, va_list argptr, int n)
{
	if (*flag == '.' || ft_isdigit(flag[n]) || *flag != '0')
	{
		sarg->precision = 1;
		if (ft_isdigit(flag[n]))
		{
			while (ft_isdigit(flag[n]))
			{
				sarg->precision_len = ((sarg->precision_len) * 10) +
					((flag[n]) - '0');
				n++;
			}
		}
		else if (flag[n] == '*')
		{
			sarg->precision_len = va_arg(argptr, int);
			n++;
		}
		else
		{
			sarg->precision_len = 0;
			n++;
		}
	}
	return (n);
}
