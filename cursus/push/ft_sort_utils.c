/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:56 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 14:59:40 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_target(int value_s, t_stack *stack)
{
	int	value_target;
	int	tmp;
	int	max;
	int	min;

	max = ft_found_max(stack);
	min = ft_found_min(stack);
	value_target = stack->value;
	tmp = max;
	if (value_s < min || value_s > max)
		return (max);
	while (stack)
	{
		if ((value_s - stack->value) < tmp && value_s - stack->value > 0)
		{
			tmp = value_s - stack->value;
			value_target = stack->value;
		}
		(stack) = stack->next;
	}
	return (value_target);
}

int	ft_calculate_move(int value_s, t_stack *stack_a, t_stack *stack_b)
{
	int		target;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		move_a;
	int		move_b;

	tmp_a = ft_found_stack(value_s, stack_a);
	target = ft_found_target(value_s, stack_b);
	tmp_b = ft_found_stack(target, stack_b);
	move_a = tmp_a->move;
	move_b = tmp_b->move;
	if (ft_size_stack(stack_a) % 2 != 0)
		move_a++;
	return (move_a + move_b);
}

int	ft_found_min_move(t_stack *stack_a, t_stack *stack_b)
{
	long	min_move;
	int		value_stack;

	value_stack = stack_a->value;
	min_move = 2147483648;
	while (stack_a)
	{
		if (ft_calculate_move(stack_a->value, stack_a, stack_b) < min_move)
		{
			min_move = ft_calculate_move(stack_a->value, stack_a, stack_b);
			value_stack = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	return (value_stack);
}

void	ft_rotate_stack_a(int min_move, t_stack **stack_a, t_stack **stack_b)
{
	int		move_a;
	t_stack	*tmps;

	tmps = ft_found_stack(min_move, *stack_a);
	move_a = tmps->move;
	if (move_a > 0)
	{
		if (ft_found_index(min_move, *stack_a) <= ft_size_stack(*stack_a) / 2)
		{
			while (move_a > 0)
			{
				ft_ra(stack_a);
				move_a--;
			}
		}
		else
		{
			while (move_a > 0)
			{
				ft_rra(stack_a);
				move_a--;
			}
		}
	}
}

void	ft_rotate_stack_b(int min_move, t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		move_b;
	t_stack	*tmps;

	target = ft_found_target(min_move, *stack_b);
	tmps = ft_found_stack(target, *stack_b);
	move_b = tmps->move;
	if (move_b > 0)
	{
		move_b++;
		if ((ft_found_index(target, *stack_b)) <= ft_size_stack(*stack_b) / 2)
		{
			while (--move_b > 0)
				ft_rb(stack_b);
		}
		else
		{
			while (--move_b > 0)
				ft_rrb(stack_b);
		}
	}
}
