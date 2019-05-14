/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:51:42 by acalkins          #+#    #+#             */
/*   Updated: 2019/04/08 16:52:14 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(sizeof(str) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	return (ft_strcpy(str, s1));
}
