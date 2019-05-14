/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:37:19 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 16:39:17 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wstostr(wchar_t *ws)
{
	char	*s;
	int		i;

	if (!ws)
		return (NULL);
	i = 0;
	s = ft_strnew(0);
	while (ws[i])
		s = ft_strjoincl(s, ft_wctostr(ws[i++]), 3);
	return (s);
}
