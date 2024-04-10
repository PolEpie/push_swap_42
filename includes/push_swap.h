/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pepie <pepie@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/10 00:59:58 by pepie			 #+#	#+#			 */
/*   Updated: 2024/03/19 14:24:58 by pepie			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_operation;


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
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);
void			pa(t_stack *stack);
void			pb(t_stack *stack);

/* operation_2 */
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);

/* operation_3 */
void			rrr(t_stack *stack);

/* first_part */
int				find_target_node(t_list_stack *stack, int number);
void			push_until_3_dest_stack(t_stack *stack, bool is_a, bool is_smaller);
void			print_operation(int op);

/* second_part */
void			sort_stack(t_stack *stack, bool is_a);

/* lst_stack.c */
t_list_stack	*ft_lstlast_stack(t_list_stack *lst);
t_list_stack	*ft_lstnew_stack(int content);
void			ft_lstadd_back_stack(t_list_stack **alst, t_list_stack *new);
int				ft_lstsize_stack(t_list_stack *lst);
void			ft_lstclear_stack(t_list_stack **lst);
int				ft_lstgetindex_stack(t_list_stack *lst, int index);

/* push_swap.c */
void			print_stacks(t_stack *stack);

#endif