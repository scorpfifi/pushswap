/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:39:35 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/28 14:49:27 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	char	**splited;
	int		i;
	int		value;
	int		max;
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*new;
	
	new = NULL;
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	i = 0;
	if (ft_check_error(argc, argv))
	{ 
		splited = ft_splited(argc, argv);
		while (splited[i])
		{
			value = ft_atoi_push(splited[i]);
			new = ft_new_list(value);
			ft_add_back(stack_a, new);
			i++;
		}
		printf("%d\n", ft_found_target(6, *stack_a));
		printf("----------------------------------------\n");
		return (0);
	}
	ft_print_error();
	return (0);
}
