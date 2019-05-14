/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:52:51 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 19:07:24 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wctostr(wchar_t c)
{
	char *s;

	s = ft_strnew(0);
	if (c <= 0x7F)
		s = ft_strjoincl(s, ft_ctostr(c, 1), 3);
	else if (c <= 0x7FF)
	{
		s = ft_strjoincl(s, ft_ctostr((c >> 6) + 0xC0, 1), 3);
		s = ft_strjoincl(s, ft_ctostr((c & 0x3F) + 0x80, 1), 3);
	}
	else if (c <= 0xFFFF)
	{
		s = ft_strjoincl(s, ft_ctostr((c >> 12) + 0xE0, 1), 3);
		s = ft_strjoincl(s, ft_ctostr(((c >> 6) & 0x3F) + 0x80, 1), 3);
		s = ft_strjoincl(s, ft_ctostr((c & 0x3F) + 0x80, 1), 3);
	}
	else if (c <= 0x10FFFF)
	{
		s = ft_strjoincl(s, ft_ctostr((c >> 18) + 0xF0, 1), 3);
		s = ft_strjoincl(s, ft_ctostr(((c >> 12) & 0x3F) + 0x80, 1), 3);
		s = ft_strjoincl(s, ft_ctostr(((c >> 6) & 0x3F) + 0x80, 1), 3);
		s = ft_strjoincl(s, ft_ctostr((c & 0x3F) + 0x80, 1), 3);
	}
	return (s);
}
