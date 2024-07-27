/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:45:38 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/16 13:40:32 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	(*src) = (*src)->next;
	tmp->next = *dest;
	(*dest) = tmp;
	ft_update_move(src);
	ft_update_move(dest);
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b)
		return ;
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return ;
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
