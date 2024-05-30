/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:50:10 by vmpianim          #+#    #+#             */
/*   Updated: 2024/02/29 14:14:23 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nb;
	char	*memb;

	nb = nmemb * size;
	memb = malloc(nb);
	if (memb == 0)
		return (0);
	else
		ft_bzero(memb, nb);
	return (memb);
}

/*int	main()
{
	char *st= "ANANAN";
	char *finst = ft_calloc(2, 4);
	printf("%s", finst);
	
}*/
