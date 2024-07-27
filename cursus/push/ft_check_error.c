/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:31:27 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/18 14:12:22 by vmpianim         ###   ########.fr       */
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
		if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
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

int	ft_check_double(t_stack *stack_a)
{
	t_stack	*current ;
	t_stack	*tmp;

	current = stack_a;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value_s == tmp->value_s)
				return (0);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_max_min(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		if (current->value_s < INT_MIN || current->value_s > INT_MAX)
			return (0);
		current = current->next;
	}
	return (1);
}
