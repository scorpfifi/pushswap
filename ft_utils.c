/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:51:03 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/28 14:37:45 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack   *ft_last_list(t_stack *stack)
{
    if(!stack)
        return (NULL);
    while (stack->next != NULL)
        stack = stack->next;
    return(stack);
}

void ft_print_value_stack(t_stack **stack)
{

    while (*stack)
    {
        printf("valeur de la stack [%d]\n", (*stack)->value);
        (*stack) = (*stack)->next;
    }
	printf("\n\n");
}

void ft_print_index_stack(t_stack **stack)
{

    while (*stack)
    {
        printf("valeur de index stack [%d]\n", (*stack)->value);
        (*stack) = (*stack)->next;
    }
	printf("\n");
}
int	ft_atoi_push(char *str)
{
	int	sign;
	int	i;
	int	results;

	results = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i ++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		results = (results * 10) + (str[i] - '0');
		i ++;
	}
	return (results * sign);
}
t_stack	*ft_new_list(int value)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack *ft_clear_stack(t_stack *stack_a)
{
	t_stack *backup_stack;

   backup_stack = stack_a;
   backup_stack = stack_a->next;
   free(stack_a);
   return (ft_clear_stack(backup_stack));
}
void ft_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_last_list(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

int	ft_found_max(t_stack *stack)
{
	int	value;
	
	value = (stack)->value;
	while (stack)
	{
		if ((stack)->value > value)
			value = (stack)->value;
		(stack) = (stack)->next;
	}
	return (value);
}

int	ft_found_min(t_stack *stack)
{
	int	value;
	
	value = (stack)->value;
	while (stack)
	{
		if ((stack)->value < value)
			value = (stack)->value;
		(stack) = (stack)->next;
	}
	return (value);
}
int	ft_found_index(int value, t_stack **stack)
{
	int	index;
	
	index = 1;
	while (*stack)
	{
		if (value == (*stack)->value)
			return (index);
		index++;
		(*stack) = (*stack)->next;
	}
	return (index);
}