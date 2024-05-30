/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:54 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/03 16:31:00 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen((char *)little);
	i = 0;
	if (!*little)
		return ((char *)&big[i]);
	while (ft_strncmp((char *)&big[i], (char *)little, strlen) != 0)
	{
		if (!*big || i >= (len - strlen))
			return (NULL);
		i++;
	}
	if (strlen > len)
		return (NULL);
	return ((char *)&big[i]);
	return (0);
}
/*

#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%s \n", ft_strnstr("bonjou", "on", 4));
	//printf("%d", ft_verify("bonjou", "on", 4));
}*/
