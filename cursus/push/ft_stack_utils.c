/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:28:26 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 14:14:42 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_list(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_new_list(long value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value_s = value;
	new->next = NULL;
	new->move = 0;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_stack	*ft_before_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	stack->next = NULL;
	return (stack);
}

t_stack	*ft_found_stack(int value_s, t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		if (stack->value == value_s)
			return (tmp);
		stack = stack->next;
	}
	return (tmp);
}
