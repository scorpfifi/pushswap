/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:39:35 by vmpianim          #+#    #+#             */
/*   Updated: 2024/06/19 11:30:49 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *ft_join_args(int argc, char **argv)
{
    char    *join;
    int     i;

    i = 1;
    if (argc < 2)
        return (NULL);
    join = ft_strdup("");
    while (argc > 1)
    {
        join = ft_strjoin(join, argv[i]);
        join = ft_strjoin(join, " ");
        i++;
        argc--;
    }
    return (join);
}
t_stack **ft_node_stack(char *str)
{
    char    **splited;
    int     value;
    int     i;
    t_stack *new;
    t_stack **stack_a;
    
    i = 0;
    splited = ft_split(str, ' ');
    stack_a = malloc(sizeof(t_stack));
	while (splited[i])
	{
		value = ft_atoi(splited[i]);
		new = ft_new_list(value);
		ft_add_back(stack_a, new);
		i++;
	}
    return (stack_a);   
}
int main(int argc, char **argv)
{
    t_stack **stack_a;
	t_stack	**stack_b;
    char    *join;

	stack_b = malloc(sizeof(t_stack));
    join = ft_join_args(argc, argv);
    stack_a = ft_node_stack(join);
    ft_print_value_stack(*stack_a);
	ft_sort_big(stack_a, stack_b);
}