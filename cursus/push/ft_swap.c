/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:35 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 13:44:24 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!(*stack) || (!(*stack)->next))
		return ;
	tmp_value = (*stack)->value_s;
	tmp_index = (*stack)->value;
	(*stack)->value_s = (*stack)->next->value_s;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value_s = tmp_value;
	(*stack)->next->value = tmp_index;
	ft_update_move(stack);
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
