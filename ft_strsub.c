/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:19:57 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/30 19:09:49 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (len <= 0 || s == NULL)
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s))
		return (NULL);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start++];
	res[i] = '\0';
	return (res);
}
