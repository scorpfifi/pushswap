/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:20:04 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 13:51:55 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*last_stack;

	last_stack = ft_last_list(*stack);
	ft_before_last_stack(*stack);
	last_stack->next = (*stack);
	(*stack) = last_stack;
	ft_update_move(stack);
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	write(1, "rrr\n", 4);
}
