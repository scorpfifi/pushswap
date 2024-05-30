/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:58:19 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/02 11:32:51 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)s);
	if ((char)c == '\0')
		return ((char *)(s + len));
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main ()
{
	char *test;
	test = "teste";
	printf ("%p \n" , &test);
	printf (" %p \n ", ft_strchr((char *)test, '\0'));
	//printf ("%s", strchr("iureyrt", 'i'));
}*/
