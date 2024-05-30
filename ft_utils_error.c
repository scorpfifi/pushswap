/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:26:07 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/23 11:52:21 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putstr_fd("error\n", 1);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == ' ')
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != '-'
			&& str[i] != '+' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
			i++;
		if ((str[i] == '-' || str[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
