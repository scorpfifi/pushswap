/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:20:04 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/25 09:36:23 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_before_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	stack->next = NULL;
	return (stack);
}

void	ft_revese(t_stack **stack)
{
	//t_stack	*before_last;
	t_stack	*last_stack;

	last_stack = ft_last_list(*stack);
	ft_before_last_stack(*stack);
	last_stack->next = (*stack);
	(*stack) = last_stack;
}

void	ft_rra(t_stack **stack_a)
{
	ft_revese(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_revese(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_revese(stack_a);
	ft_revese(stack_b);
	write(1, "rrr\n", 4);
}