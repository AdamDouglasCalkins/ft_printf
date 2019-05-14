/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:46:16 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/06 19:40:48 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		inner_print(char *flag, int i, va_list argptr)
{
	int		count;
	t_args	sarg;

	ft_bzero(&sarg, sizeof(sarg));
	ft_get_args(flag, argptr, &sarg);
	if (flag[i] == 'd' || flag[i] == 'D' || flag[i] == 'i')
		count = ft_print_d(flag[i], &sarg, argptr);
	if (flag[i] == 'x')
		count = ft_print_x(&sarg, argptr);
	if (flag[i] == 'X')
		count = ft_print_upper_x(&sarg, argptr);
	if (flag[i] == 'u' || flag[i] == 'U')
		count = ft_print_u(flag[i], &sarg, argptr);
	if (flag[i] == 'o' || flag[i] == 'O')
		count = ft_print_o(flag[i], &sarg, argptr);
	if (flag[i] == 'c' || flag[i] == 'C')
		count = ft_print_c(&sarg, argptr);
	if (flag[i] == 's' || flag[i] == 'S')
		count = ft_print_s(&sarg, argptr);
	if (flag[i] == 'p')
		count = ft_print_p(&sarg, argptr);
	if (flag[i] == '%')
		count = ft_print_per(&sarg);
	free(flag);
	return (count);
}
