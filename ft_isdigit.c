/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:21:20 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 17:21:48 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}