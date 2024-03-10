/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:59:58 by pepie             #+#    #+#             */
/*   Updated: 2024/03/10 00:59:58 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


typedef struct s_list_stack
{
	int					content;
	struct s_list_stack	*next;
}				t_list_stack;
typedef struct s_stack
{
	t_list_stack	*stack_a;
	t_list_stack	*stack_b;
	int				size_a;
	int				size_b;
}				t_stack;

/* operation_1 */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

/* operation_2 */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

/* operation_3 */
void	rrr(t_stack *stack);

/* target */

/* first_part */
int		find_target_node(t_list_stack *stack, int number);
void	push_until_3_dest_stack(t_stack *stack, bool is_a);

#endif