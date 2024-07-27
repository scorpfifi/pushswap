/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:20:41 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/19 10:56:13 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendest;

	lendest = 0;
	lensrc = ft_strlen((char *)src);
	if (*dest == 0 && *src == 0)
		return (0);
	while (*dest && size > 0)
	{
		lendest++;
		dest++;
		size--;
	}
	while (*src && size > 1)
	{
		*dest ++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
		*dest = '\0';
	return (lendest + lensrc);
}
