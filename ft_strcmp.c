/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:44:49 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 16:45:52 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(char *s1, char *s2)
{
	int num1;

	num1 = 0;
	while (s1[num1] == s2[num1] && s1[num1] != '\0' && s2[num1] != '\0')
	{
		num1++;
	}
	return ((unsigned char)s1[num1] - (unsigned char)s2[num1]);
}
