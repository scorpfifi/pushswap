/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:24:57 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/08 15:40:09 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	lenfin;

	lenfin = 0;
	if (s == NULL || start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s) - start)
		lenfin = ft_strlen(s) - (start);
	else
		lenfin = len;
	dest = (char *)malloc((lenfin * sizeof(char)) + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, (s + start), lenfin);
	dest[lenfin] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char *test;
	test = ft_substr("tripuillle", 0, 42000);
	printf("%s", test);
}*/
