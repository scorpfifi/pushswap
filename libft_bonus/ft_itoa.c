/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:59:30 by vmpianim          #+#    #+#             */
/*   Updated: 2024/03/03 17:10:21 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n *= -1;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*tmp;
	int		nb;

	sign = 0;
	nb = ft_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = (char *)malloc(sizeof(char) * (nb + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[nb] = '\0';
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (--nb >= 0)
	{
		tmp[nb] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		tmp[0] = 45;
	return (tmp);
}
