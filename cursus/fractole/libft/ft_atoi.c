/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:59:56 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/18 14:16:41 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atoi(const char *str)
{
	long	sign;
	int		i;
	long	results;

	results = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i ++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		results = (results * 10) + (str[i] - '0');
		i ++;
	}
	return (results * sign);
}
