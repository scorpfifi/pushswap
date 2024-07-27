/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:03 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 14:27:17 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_max(t_stack *stack)
{
	int	value;

	value = (stack)->value;
	while (stack)
	{
		if ((stack)->value > value)
			value = (stack)->value;
		(stack) = (stack)->next;
	}
	return (value);
}

int	ft_found_min(t_stack *stack)
{
	int	value;

	value = (stack)->value;
	while (stack)
	{
		if ((stack)->value < value)
			value = (stack)->value;
		(stack) = (stack)->next;
	}
	return (value);
}

int	ft_found_index(int value, t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (value == (stack)->value)
			return (index);
		index++;
		(stack) = (stack)->next;
	}
	return (index);
}

void	ft_find_place_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (stack)
	{
		tmp = stack;
		while (tmp)
		{
			if (ft_min_index(stack) == tmp->value_s)
			{
				i++;
				tmp->value = i;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		stack = stack->next;
	}
}
