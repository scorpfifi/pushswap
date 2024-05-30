/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:16:22 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/02 09:07:35 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc ((ft_strlen((char *)s) + 1) * sizeof(char));
	i = 0;
	if (dest == 0)
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest [i] = '\0';
	return ((char *)dest);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	printf("%s \n", strdup("\0"));
	printf("%s", ft_strdup("\0"));
}*/
