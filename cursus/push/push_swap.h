/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:33 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/18 14:15:13 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft_bonus/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long				value;
	long				value_s;
	int					move;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;
void ft_print_stack(t_stack *stack);
char	*ft_join_args(int argc, char **argv);
t_stack	**ft_add_node(int argc, char **argv);
t_stack	*ft_last_list(t_stack *stack);
t_stack	*ft_new_list(long value);
void	ft_add_back(t_stack **stack, t_stack *new_node);
t_stack	*ft_before_last_stack(t_stack *stack);
t_stack	*ft_found_stack(int value_s, t_stack *stack);
int		ft_found_max(t_stack *stack);
int		ft_found_min(t_stack *stack);
int		ft_found_index(int value, t_stack *stack);
void	ft_find_place_index(t_stack *stack);
int		ft_size_stack(t_stack *stack);
void	ft_update_move(t_stack **stack);
int		ft_is_sorted(t_stack *stack);
long	ft_min_index(t_stack *stack);
void	ft_initialise_index(t_stack *stack);
void	ft_push(t_stack **src, t_stack **dest);
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_stack(t_stack **stack_a);
void	ft_sort_big(t_stack **stack_a, t_stack **stack_b);
void	ft_push_inb(t_stack **stack_a, t_stack **stack_b);
void	ft_push_final(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_b_max(t_stack **stack_b);
int		ft_found_target(int value_s, t_stack *stack);
int		ft_calculate_move(int value_s, t_stack *stack_a, t_stack *stack_b);
int		ft_found_min_move(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_stack_a(int min_move, t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_stack_b(int min_move, t_stack **stack_a, t_stack **stack_b);
void	ft_print_error(void);
int		ft_check_digit(char *str);
int		ft_check_double_sign(char *str);
int		ft_check_double(t_stack *stack_a);
int		ft_check_max_min(t_stack *stack_a);
void	ft_free_stack(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a_min(t_stack **stack_a);

#endif
