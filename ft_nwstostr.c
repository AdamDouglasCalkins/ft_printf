/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwstostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:39:38 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/23 17:58:16 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_nwstostr(wchar_t *ws, size_t len)
{
	char	*s;
	char	*s2;
	int		i;

	if (!ws)
		return (NULL);
	i = 0;
	s = ft_strnew(0);
	s2 = NULL;
	while (ws[i] && ft_strlen(s) <= len)
	{
		ft_strdel((char**)&s2);
		s2 = ft_strdup(s);
		s = ft_strjoincl(s, ft_wctostr(ws[i++]), 3);
	}
	ft_strdel((char**)&s);
	free(s);
	return (s2);
}
