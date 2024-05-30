/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_threestack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:12 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/25 09:50:10 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    ft_sort_three(t_stack **stack_a)
{
    int middle;
    int top;
    int bottom;
    
    top = (*stack_a)->value;
    middle = (*stack_a)->next->value;
    bottom = (*stack_a)->next->next->value;
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

