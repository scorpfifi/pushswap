/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:59:30 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/03 16:51:05 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		lenfin;
	char	*dest;

	i = 0;
	j = 0;
	lenfin = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	dest = malloc(lenfin * sizeof(char) + 1);
	if (dest == 0)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest [i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main ()
{
	printf("%s", ft_strjoin("12", "1233"));
}*/
