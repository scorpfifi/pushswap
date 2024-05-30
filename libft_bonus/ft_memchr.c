/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:30:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/02/29 09:50:08 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main ()
{
//	printf ("anana");
	char *ch;
	char *ch2;
	ch = (char *)ft_memchr("bonjour", '2',10);
	//ch2= (char *)memchr("bonjour", '2',10);
	printf("%s\n%s", ch, ch2);
}*/
