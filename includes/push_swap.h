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
}				t_list_s;
typedef struct s_stack
{
	t_list_s	*stack_a;
	t_list_s	*stack_b;
	int			size_a;
	int			size_b;
}				t_stack;

typedef enum e_direction
{
	UP,
	DOWN,
	NONE
}				t_direction;

typedef struct s_move
{
	int				index_src;
	int				index_dst;
	int				src_go_up;
	int				dst_go_up;
	int				cost;
	int				len_in;
	int				len_out;
	int				gap_a;
	int				gap_b;
	t_list_s		*tmp;
}	t_move;

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
int				find_target_node(t_list_s *stack, int number);
bool			push_until_3_dest_stack(t_stack *stack);
void			print_operation(int op);
bool			is_stack_sorted(t_list_s *src);
t_list_s		*find_cost(t_stack *stk, int i_src, int i_dst, bool is_a_s);
void			perform_lst(t_list_s **lst, t_stack *stack);

/* second_part */
void			sort_stack_max_3(t_stack *stack);
void			sort_stack_with_rotation(t_stack *stack);

/* last_part */
bool			push_until_finish(t_stack *stack);

/* lst_stack.c */
t_list_s		*ft_lstlast_stack(t_list_s *lst);
t_list_s		*ft_lstnew_stack(int content);
bool			ft_lstadd_back_stack(t_list_s **alst, t_list_s *new);
int				ft_lstsize_stack(t_list_s *lst);

/* lst_stack_2.c */
void			ft_lstclear_stack(t_list_s **lst);
int				ft_lstgetindex_stack(t_list_s *lst, int index);

/* find_target.c */
int				find_target_node_small(t_list_s *stack, int number);
int				find_target_node_big(t_list_s *stack, int number);

/* push_swap.c */
void			print_stacks(t_stack *stack);

/* move_stack */
int				handle_move_both_stack(t_move *mv);
void			handle_move_one_stack(t_move *mv, bool is_a_in, bool is_src);

void			find_target_and_push_low(t_stack *stack, t_list_s *src, t_list_s *dst);

#endif