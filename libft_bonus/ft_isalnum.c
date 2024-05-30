/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:23:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/02/24 16:26:15 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	int	alpha;
	int	digit;

	alpha = ft_isalpha(c);
	digit = ft_isdigit(c);
	if (alpha == 1 || digit == 1)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main ()
{
	printf("%d", ft_isalnum('6'));
	printf("%d", ft_isalnum('*'));
}*/
