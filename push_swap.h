/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:52:04 by vmpianim          #+#    #+#             */
/*   Updated: 2024/06/05 14:11:29 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
#include <stdlib.h>
#include "libft_bonus/libft.h"
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				move;
	struct s_stack	*next;
}	t_stack;
t_stack *ft_clear_stack(t_stack *stack_a);
t_stack	*ft_new_list(int value);
void ft_add_back(t_stack **alst, t_stack *new);
void    ft_print_value_stack(t_stack *stack);
void	ft_print_index_stack(t_stack **stack);
char	**ft_splited(int argc, char **argv);
t_stack   *ft_last_list(t_stack *stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_before_last_stack(t_stack *stack);
void	ft_revese(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_print_error(void);
int		ft_check_digit(char *str);
int		ft_check_double_sign(char *str);
int		ft_check_string(char *str);
char	*ft_generate_char(int argc, char **argv);
int		ft_check_error(int argc, char **argv);
int	ft_atoi_push(char *str);
void    ft_sort_three(t_stack **stack_a);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void    ft_sort_big(t_stack **stack_a, t_stack **stack_b);
int		ft_found_max(t_stack *stack);
int	ft_found_min(t_stack *stack);
int	ft_found_index(int value, t_stack *stack);
int ft_found_target(int value_s, t_stack *stack);
int ft_calculate_move (int value_s, t_stack *stack);
int	ft_size_stack(t_stack *stack);
int ft_found_min_move(t_stack *stack_a, t_stack *stack_b);
void    ft_execute_move(t_stack **stack_a, t_stack **stack_b);
#endif
