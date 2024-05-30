/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:38:43 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/08 15:33:30 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
#include <string.h>
#include <stdio.h>
int	main ()
{
	char *s1;
	char *s2;
	s1 = NULL;
	s2 = NULL;

	printf("%s", (char *)memcpy(s1, s2, 3)); 
}*/
