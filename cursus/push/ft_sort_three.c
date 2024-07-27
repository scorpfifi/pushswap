/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:31:44 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:13 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	middle;
	int	top;
	int	bottom;

	top = (*stack_a)->value_s;
	middle = (*stack_a)->next->value_s;
	bottom = (*stack_a)->next->next->value_s;
	if (top > middle && middle < bottom && bottom > top)
		ft_sa(stack_a);
	else if (top > middle && middle > bottom && bottom < top)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top > middle && middle < bottom && bottom < top)
		ft_ra(stack_a);
	else if (top < middle && middle > bottom && bottom > top)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else
		ft_rra(stack_a);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size_stack(*stack_a);
	while (size > 3)
	{
		ft_rotate_a_min(stack_a);
		ft_pb(stack_a, stack_b);
		size--;
	}
	size = ft_size_stack(*stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	while (size > 0)
	{
		ft_pa(stack_a, stack_b);
		size--;
	}
	ft_free_stack(stack_b);
}

void	ft_rotate_a_min(t_stack **stack_a)
{
	int		move;
	int		min;
	t_stack	*tmp;

	min = ft_found_min(*stack_a);
	tmp = ft_found_stack(min, *stack_a);
	move = tmp->move;
	if (move == 0)
		return ;
	if (ft_found_index(min, *stack_a) <= ft_size_stack(*stack_a) / 2)
	{
		while (move > 0)
		{
			ft_ra(stack_a);
			move--;
		}
	}
	else
	{
		while (move > 0)
		{
			ft_rra(stack_a);
			move--;
		}
	}
}
