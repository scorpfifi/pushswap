/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:45:38 by vmpianim          #+#    #+#             */
/*   Updated: 2024/06/12 11:11:04 by vmpianim         ###   ########.fr       */
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
// int main() {
//     t_stack *stack = NULL;
//     t_stack *stack_b;

// 	stack_b = malloc(sizeof(t_stack));
//     for (int i = 3; i >= 1; i--)
//     {
//         t_stack *new_node = malloc(sizeof(t_stack));
//         if (!new_node)
//             return 0;
//         new_node->value = i;
//         new_node->next = stack;
//         stack = new_node;
//     }
//     printf("Pile A avant ft_pb : \n");
//     ft_print_stack(stack);
//     printf("Pile B avant  ft_pb : \n");
//     ft_print_stack(stack_b);
//     printf("--------------------------------------------------\n");
//     ft_pb(&stack, &stack_b);
//     printf("--------------------------------------------------\n");
//     printf("Pile après A ft_pb : \n");
//     ft_print_stack(stack);
//     printf("Pile apres B ft_b : \n");
//     ft_print_stack(stack_b);
//     return 0;
// }