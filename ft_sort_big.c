/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:33:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/06/05 14:15:20 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
    //1.pushed 2 number to stack
    printf("1. pusher deux element dans stackb\n");
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    ft_print_value_stack(*stack_a);
    ft_print_value_stack(*stack_b);
    printf ("--------------------------------------\n");
    int size;

    size = ft_size_stack(*stack_a);
    ft_execute_move(stack_a, stack_b);
    
}
int ft_found_target(int value_s, t_stack *stack)
{
    int value_target;
    int tmp;
    int max;
    int min;
    
    max = ft_found_max(stack);
    min = ft_found_min(stack);
    tmp = value_s - stack->value;
    value_target = stack->value;
    if (value_s < min || value_s > max)
    {
        return (max);
    }
    while (stack)
    {
        if ((value_s - stack->value) < tmp && (value_s - stack->value) > 0)
        {
            tmp = value_s - stack->value;
            value_target = stack->value;
        }
        (stack) = stack->next;
    }
     return(value_target);
}

int ft_calculate_move (int value_s, t_stack *stack)
{
    int target;
    int pos_target;
    int move;


    target = ft_found_target(value_s, stack);
    pos_target = ft_found_index(target, stack);
    if (pos_target <= ft_size_stack(stack) / 2)
    {
        move = ft_found_index(target, stack);
    }
    else
    {
        move = pos_target - (ft_size_stack(stack) / 2) + 1;
    } 
    return (move);                      
}

int ft_found_min_move(t_stack *stack_a, t_stack *stack_b)
{
    int min_move;
    int value_stack;
    
    value_stack = stack_a->value;
    min_move = ft_calculate_move(stack_a->value, stack_b);
    while (stack_a)
    {
        if (ft_calculate_move(stack_a->value, stack_b) < min_move)
        {
            min_move = ft_calculate_move(stack_a->value, stack_b);
            value_stack = stack_a->value;
        }
        stack_a = stack_a->next;
    }
    return (value_stack);
}

void    ft_execute_move(t_stack **stack_a, t_stack **stack_b)
{
    int value_stack;
    int value_index;

    value_stack = ft_found_min_move(*stack_a, *stack_b);
    value_index = ft_found_index(value_stack, *stack_a);
    
    if (value_index <= ft_size_stack(*stack_a) / 2)
    {
        while (value_index > 1)
        {
            ft_ra(stack_a);
            value_index--;
        }
        ft_pb(stack_a, stack_b);
    ft_print_value_stack(*stack_a);
    ft_print_value_stack(*stack_b);
    }
}