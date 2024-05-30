/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:33:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/28 14:49:06 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
    //1.pushed 2 number to stack
    printf("1. pusher deux element dans stackb\n");
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    ft_print_value_stack(stack_a);
    ft_print_value_stack(stack_b);
    printf ("--------------------------------------\n");
    //2. find the cheapest number
        //*calculate mouve
            // find min and max
    
}
int ft_found_target(int value_s, t_stack *stack)
{
    int value_target;
    int tmp;
    int val_tmp;
    int max;
    int min;
    
    max = ft_found_max(stack);
    min = ft_found_min(stack);
    tmp = value_s - stack->value;
    value_target = stack->value;
    if (value_s < min || value_s > max)
    {
        printf ("1\n");
        return (max);
    }
    while (stack)
    {
        if ((value_s - stack->value) < tmp && (value_s - stack->value) > 0)
        {
            tmp = value_s - stack->value;
            value_target = stack->value;
        }
        tmp = tmp;
        (stack) = stack->next;
    }
     return(value_target);
}