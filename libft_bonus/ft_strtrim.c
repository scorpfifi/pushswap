/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:03:33 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/03 16:47:02 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify(const char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	while (*s1)
	{
		if (verify((const char)*s1, set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len != 0)
	{
		if (verify((const char )s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	dest = (char *)malloc((len * sizeof(char)) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, (len + 1));
	return (dest);
}
/*
#include<stdio.h>
int	main (void)
{
	//count("anabojourana", "ana");
	printf("%s",ft_strtrim("anabonjouranaana", "ana"));
}*/
