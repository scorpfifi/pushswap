/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:33:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/06/19 11:26:40 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
    //1.pushed 2 number to stack
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    int min_move;
    int pos_a;
    int pos_b;
    int i;
    int target;

    i = ft_size_stack(*stack_a);
    printf ("2***************** ");
    while (i > 3)
    {  
        min_move = ft_found_min_move(*stack_a, *stack_b);
        target = ft_found_target(min_move, *stack_b);
        pos_b = ft_found_index(target, *stack_b);
        pos_a = ft_found_index(min_move, *stack_a);
        ft_execute_move_stack(pos_a, *stack_a, *stack_b);
        ft_execute_move_stack(pos_b, *stack_b, *stack_b);
        i--;
    }
    ft_print_value_stack(*stack_a);
    ft_print_value_stack(*stack_b);
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

int ft_calculate_move (int value_s, t_stack *stack_a, t_stack *stack_b)
{
    int target;
    int pos_target;
    int move_a;
    int move_b;

    target = ft_found_target(value_s, stack_b);
    // move_a
    if (ft_found_index(value_s, stack_a) <= ft_size_stack(stack_a) / 2)
        move_a = ft_found_index(value_s, stack_a) - 1;
    else
        move_a = ft_found_index(value_s, stack_a) - ft_size_stack(stack_a) / 2;
    // move b
    if (ft_found_index(target, stack_b) <= ft_size_stack(stack_b) / 2)
        move_a = ft_found_index(target, stack_b) - 1;
    else
        move_a = ft_found_index(target, stack_b) - ft_size_stack(stack_b) / 2;
    return (move_a + move_b);                
}


int ft_found_min_move(t_stack *stack_a, t_stack *stack_b)
{
    int min_move;
    int value_stack;
    
    value_stack = stack_a->value;
    min_move = ft_calculate_move(stack_a->value, stack_a, stack_b);
    while (stack_a)
    {
        if (ft_calculate_move(stack_a->value, stack_a, stack_b) < min_move)
        {
            min_move = ft_calculate_move(stack_a->value, stack_a, stack_a);
            value_stack = stack_a->value;
        }
        stack_a = stack_a->next;
    }
    return (value_stack);
}
void    ft_execute_move_stack(int pos, t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int i;
    
    size = ft_size_stack(stack_a);
    if (pos <= size / 2)
    {
        i = pos;
        printf ("valeur ");
        while (i > 0)
        {
            printf ("valeur ");
            ft_ra(&stack_a);
            i--;
        }
        ft_pb(&stack_a, &stack_b);  
    }
    else
    {
        i = pos - size / 2;
        while (i > 0)
        {
            ft_rra(&stack_a);
            i--;
        }
        ft_pb(&stack_a, &stack_b);
    }
}
    
void    ft_execute_move(t_stack *stack_a, t_stack *stack_b)
{
    return;
}