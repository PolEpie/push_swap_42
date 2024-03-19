/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   first_part.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pepie <pepie@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/10 02:26:56 by pepie			 #+#	#+#			 */
/*   Updated: 2024/03/19 14:25:31 by pepie			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"


int		find_target_node(t_list_stack *stack, int number)
{
	t_list_stack	*tmp;
	int				i;
	int				target_index;
	int				target_value;

	tmp = stack;
	i = 0;
	target_index = -1;
	target_value = 0;
	while (stack)
	{
		if (stack->content < number && (stack->content > target_value || target_index == -1))
		{
			target_index = i;
			target_value = stack->content;
		}
		stack = stack->next;
		i++;
	}
	if (target_index == -1)
	{
		stack = tmp;
		i = 0;
		while (stack)
		{
			if (stack->content > target_value || target_index == -1)
			{
				target_index = i;
				target_value = stack->content;
			}
			stack = stack->next;
			i++;
		}
	}
	return (target_index);
}

void	case_0_cost(t_stack *stack, bool is_a, int target_len)
{
	if (is_a)
		pb(stack);
	else
		pa(stack);
	if (is_a)
		target_len = stack->size_a;
	else
		target_len = stack->size_b;
	if (target_len > 3)
		push_until_3_dest_stack(stack, is_a);
	return ;
}

typedef enum e_direction
{
	UP,
	DOWN,
	NONE
}				t_direction;

t_direction should_go_up(int index, int size)
{
	if (index == 0)
		return (NONE);
	else if (index <= size / 2)
		return (UP);
	else
		return (DOWN);
}

typedef struct s_move
{
	int index_src;
	int index_dst;
	int src_go_up;
	int dst_go_up;
	int cost;
	t_list_stack *tmp;
	int len_in;
	int len_out;
	int gap_a;
	int gap_b;
}				t_move;

void	get_gap(t_move *mv)
{
	if (mv->src_go_up == UP)
		mv->gap_a = mv->index_src;
	else if (mv->src_go_up == DOWN)
		mv->gap_a = mv->len_in - mv->index_src;
	else
		mv->gap_a = 0;
	if (mv->dst_go_up == UP)
		mv->gap_b = mv->index_dst;
	else if (mv->dst_go_up == DOWN)
		mv->gap_b = mv->len_out - mv->index_dst;
	else	
		mv->gap_b = 0;
}

int handle_move_both_stack(t_move *mv)
{
	int i;
	int gap;

	i = 0;
	if (mv->src_go_up == UP)
	{
		gap = ft_mathmin(mv->gap_a, mv->gap_b);
		while (i < gap)
		{
			mv->cost++;
			ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(RR));
			i++;
		}
		mv->gap_a -= gap;
		mv->gap_b -= gap;
	}
	else if (mv->src_go_up == DOWN)
	{
		gap = ft_mathmin(mv->gap_a, mv->gap_b);
		while (i < gap)
		{
			mv->cost++;
			ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(RRA));
			i++;
		}
		mv->gap_a -= gap;
		mv->gap_b -= gap;
	}
	return (0);
}

int handle_move_one_stack(t_move *mv, bool is_a)
{
	int i;
	int gap;
	int dir;
	int op;

	i = 0;
	if (is_a)
	{
		dir = mv->src_go_up;
		gap = mv->gap_a;
	}
	else
	{
		dir = mv->dst_go_up;
		gap = mv->gap_b;
	}
	if (dir == UP)
		op = RA;
	else if (dir == DOWN)
		op = RRA;
	else
		return (0);
    if (!is_a)
        op += 1;
    while (i < gap)
    {
		ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(op));
		mv->cost = mv->cost + 1;
		i++;
	}
	return (0);
}

void	print_lst(t_list_stack **lst)
{
	t_list_stack *tmp;

	tmp = *lst;
	ft_printf("####################\n");
	while (tmp)
	{
		if (tmp->content == 0)
			ft_printf("SA\n");
		else if (tmp->content == 1)
			ft_printf("SB\n");
		else if (tmp->content == 2)
			ft_printf("SS\n");
		else if (tmp->content == 3)
			ft_printf("PA\n");
		else if (tmp->content == 4)
			ft_printf("PB\n");
		else if (tmp->content == 5)
			ft_printf("RA\n");
		else if (tmp->content == 6)
			ft_printf("RB\n");
		else if (tmp->content == 7)
			ft_printf("RR\n");
		else if (tmp->content == 8)
			ft_printf("RRA\n");
		else if (tmp->content == 9)
			ft_printf("RRB\n");
		else if (tmp->content == 10)
			ft_printf("RRR\n");
		tmp = tmp->next;
	}
	ft_printf("####################\n");
}

int find_cost(t_stack *stk, int index_src, int index_dst, bool is_a_in)
{
	t_move *mv;

	mv = malloc(sizeof(t_move));
	if (!mv)
		return (-1);
	mv->index_src = index_src;
	mv->index_dst = index_dst;
	mv->tmp = NULL;
	mv->cost = 0;
	if (is_a_in)
	{
		mv->len_in = stk->size_a;
		mv->len_out = stk->size_b;
	} else {
		mv->len_in = stk->size_b;
		mv->len_out = stk->size_a;
	}
	mv->src_go_up = should_go_up(index_src, mv->len_in);
	mv->dst_go_up = should_go_up(index_dst, mv->len_out);
	get_gap(mv);
	ft_printf("src_go_up: %d,\tdst_go_up: %d\t|\tgap_a: %d\tgap_b: %d\n", mv->src_go_up, mv->dst_go_up, mv->gap_a, mv->gap_b);
	if (mv->src_go_up == mv->dst_go_up && mv->src_go_up != NONE)
		handle_move_both_stack(mv);
	handle_move_one_stack(mv, false);
	handle_move_one_stack(mv, true);
    if (is_a_in)
        ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(PB));
    else
        ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(PA));
	    print_lst(&mv->tmp);
	return (mv->cost);
}

void	push_until_3_dest_stack(t_stack *stack, bool is_a)
{
	t_list_stack	*src;
	t_list_stack	*dst;
	int				i;
	int				target_len;
	int				lowest_cost; 
	int				lowest_cost_index;
	int				cost;

	i = 0;
	lowest_cost = 9999999;
	lowest_cost_index = -1;
	if (is_a)
	{
		target_len = stack->size_a;
		src = stack->stack_a;
		dst = stack->stack_b;
	}
	else
	{
		target_len = stack->size_b;
		src = stack->stack_b;
		dst = stack->stack_a;
	}
	print_stacks(stack);
	while (i < target_len)
	{
		cost = find_cost(stack, i, find_target_node(dst, src->content), is_a);
		ft_printf("cost: %d: %d\n", src->content, cost);
		if (cost == 0)
			return case_0_cost(stack, is_a, target_len);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			lowest_cost_index = i;
		}
		i++;
		src = src->next;
	}
    
	/* if (target_len > 3)
		push_until_3_dest_stack(stack, is_a); */
}
