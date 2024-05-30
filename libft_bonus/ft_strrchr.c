/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:55:41 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/02 11:34:06 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen((char *) s);
	if ((char)c == '\0')
		return ((char *) s + len);
	while (len-- > 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)s + len);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	printf("%s \n", strrchr("bonjour", '\0'));
	printf("%s \n", ft_strrchr("bonjour", '\0'));

}*/
