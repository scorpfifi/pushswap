/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:05:08 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 14:44:32 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_size_stack(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_size_stack(*stack_a) > 3 && ft_size_stack(*stack_a) <= 5)
		ft_sort_five(stack_a, &stack_b);
	else if (ft_size_stack(*stack_a) == 2)
	{
		if ((*stack_a)->value_s > (*stack_a)->next->value_s)
			ft_sa(stack_a);
	}
	else
		ft_sort_big(stack_a, &stack_b);
}

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_inb(stack_a, stack_b);
	ft_rotate_b_max(stack_b);
	ft_push_final(stack_a, stack_b);
	ft_free_stack(stack_b);
}

void	ft_push_inb(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min_move;

	size = ft_size_stack(*stack_a);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	size = ft_size_stack(*stack_a);
	while (size > 0)
	{
		min_move = ft_found_min_move(*stack_a, *stack_b);
		ft_rotate_stack_b(min_move, stack_a, stack_b);
		ft_rotate_stack_a(min_move, stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		size--;
	}
}

void	ft_rotate_b_max(t_stack **stack_b)
{
	int		move;
	int		max;
	t_stack	*tmp;

	max = ft_found_max(*stack_b);
	tmp = ft_found_stack(max, *stack_b);
	move = tmp->move;
	if (move == 0)
		return ;
	if (ft_found_index(max, *stack_b) <= ft_size_stack(*stack_b) / 2)
	{
		while (move > 0)
		{
			ft_rb(stack_b);
			move--;
		}
	}
	else
	{
		while (move > 0)
		{
			ft_rrb(stack_b);
			move--;
		}
	}
}

void	ft_push_final(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size_stack(*stack_b);
	while (size > 0)
	{
		ft_pa(stack_b, stack_a);
		size--;
	}
}
