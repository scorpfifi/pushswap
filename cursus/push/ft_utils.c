/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:45:59 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 14:30:14 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	ft_update_move(t_stack **stack)
{
	int		index;
	int		size;
	int		i;
	t_stack	*tmp;

	index = 0;
	tmp = *stack;
	size = ft_size_stack(tmp);
	if (!*stack)
		return ;
	while (index <= (size / 2))
	{
		tmp->move = index;
		index++;
		tmp = tmp->next;
	}
	i = size / 2;
	if (ft_size_stack(*stack) % 2 == 0)
		i--;
	while (i > 0)
	{
		tmp->move = i;
		i--;
		tmp = tmp->next;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*cur;
	int		min;

	cur = stack;
	min = cur->value;
	cur = cur->next;
	while (cur)
	{
		if (min < cur->value)
		{
			min = cur->value;
			cur = cur->next;
		}
		else
			return (0);
	}
	return (1);
}

long	ft_min_index(t_stack *stack)
{
	long	min;
	t_stack	*tmp;

	min = 2147483648;
	if (min == -2147483648)
		return (-2147483648);
	while (stack)
	{
		if (stack->value_s < min && stack->value == -1)
			min = stack->value_s;
		stack = stack->next;
	}
	return (min);
}

void	ft_initialise_index(t_stack *stack)
{
	while (stack)
	{
		stack->value = -1;
		stack = stack->next;
	}
}

void ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("valeur de la stack_value[%ld] avec index [%ld] move = %i \n", stack->value_s, stack->value, stack->move);
		stack = stack->next;
	}
	printf("\n\n");
}