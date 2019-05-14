/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:09:52 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/06 19:43:13 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_nbstr(char flag, t_args *sarg, va_list larg, char *sign)
{
	intmax_t	nb;
	uintmax_t	unb;

	*sign = '+';
	if (flag == 'D')
		nb = (long)(va_arg(larg, long int));
	else
		nb = ft_signed_from_lenght(sarg, va_arg(larg, intmax_t));
	if (nb < 0)
	{
		unb = (uintmax_t)-nb;
		*sign = '-';
	}
	else
		unb = (uintmax_t)nb;
	if (unb == 0 && sarg->precision)
		return (ft_strnew(0));
	return (ft_uimtoa(unb));
}
