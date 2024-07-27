/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:08:40 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/18 14:14:35 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_args(int argc, char **argv)
{
	char	*join;
	char	*join_final;
	int		i;

	join = ft_strdup("");
	i = 1;
	if (argc < 2)
		return (NULL);
	while (argc > 1)
	{
		join = ft_strjoin(join, argv[i]);
		join = ft_strjoin(join, " ");
		i++;
		argc--;
	}
	return (join);
}

t_stack	**ft_add_node(int argc, char **argv)
{
	long	value;
	int		i;
	t_stack	**stack_a;
	char	**splited;
	char	*join;

	join = ft_join_args(argc, argv);
	i = -1;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (free(stack_a), NULL);
	*stack_a = NULL;
	splited = ft_split(join, ' ');
	while (splited[++i])
	{
		value = ft_atoi(splited[i]);
		ft_add_back(stack_a, ft_new_list(value));
		free(splited[i]);
	}
	if (!*stack_a || !ft_check_digit(join) || !ft_check_double_sign(join))
	{
		ft_free_stack(stack_a);
		return (free(join), free(splited), free(stack_a), NULL);
	}
	return (free(join), free(splited), stack_a);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;

	if (argc < 2)
		return (0);
	stack_a = ft_add_node(argc, argv);
	if (!stack_a)
	{
		ft_print_error();
		return (free(stack_a), 0);
	}
	if (!ft_check_double(*stack_a) || !ft_check_max_min(*stack_a))
	{
		ft_print_error();
		ft_free_stack(stack_a);
		return (free(stack_a), 0);
	}
	ft_initialise_index(*stack_a);
	ft_update_move(stack_a);
	ft_find_place_index(*stack_a);
	//ft_print_stack(*stack_a);
	if (!ft_is_sorted(*stack_a))
		ft_sort_stack(stack_a);
	ft_free_stack(stack_a);
	free(stack_a);
	return (0);
}
