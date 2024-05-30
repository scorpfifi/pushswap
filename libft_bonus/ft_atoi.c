/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:59:56 by vmpianim          #+#    #+#             */
/*   Updated: 2024/02/29 13:54:55 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	results;

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
/*
#include <stdio.h>

int	main (int argc, char *argv[])
{
	if (argc > 1)
	{
		//printf("%s\n", argv[1]);
		printf("atoi %d\n", atoi(argv[1]));
		printf("ft_atoi %d", ft_atoi(argv[1]));
	}
}*/
