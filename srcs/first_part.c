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

int		find_target_node_small(t_list_stack *stack, int number)
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

void	case_0_cost(t_stack *stack, bool is_a)
{
	if (is_a)
	{
		pb(stack);
		print_operation(PB);
	}
	else
	{
		pa(stack);
		print_operation(PA);
	}
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

int	ft_mathmin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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

int handle_move_one_stack(t_move *mv, bool is_a_in, bool is_src)
{
	int i;
	int gap;
	int dir;
	int op;

	i = 0;
	if (is_src)
	{
		dir = mv->src_go_up;
		gap = mv->gap_a;
	}
	else
	{
		dir = mv->dst_go_up;
		gap = mv->gap_b;
	}
	//mv->tmp = NULL;
	//ft_printf("dir: %d\tgap: %d %d\n", dir, gap, is_src);
	if (dir == UP)
		op = RA;
	else if (dir == DOWN)
		op = RRA;
	else
		return (0);
    if (!is_a_in)
        op += 1;
    while (i < gap)
    {
		ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(op));
		//print_operation(op);
		mv->cost = mv->cost + 1;
		i++;
	}
	return (0);
}

void	print_operation(int op)
{
	if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
}

void	perform_lst(t_list_stack **lst, t_stack *stack)
{
	t_list_stack *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content == SA)
			sa(stack);
		else if (tmp->content == SB)
			sb(stack);
		else if (tmp->content == SS)
			ss(stack);
		else if (tmp->content == PA)
			pa(stack);
		else if (tmp->content == PB)
			pb(stack);
		else if (tmp->content == RA)
			ra(stack);
		else if (tmp->content == RB)
			rb(stack);
		else if (tmp->content == RR)
			rr(stack);
		else if (tmp->content == RRA)
			rra(stack);
		else if (tmp->content == RRB)
			rrb(stack);
		else if (tmp->content == RRR)
			rrr(stack);
		print_operation(tmp->content);
		tmp = tmp->next;
	}
}

t_list_stack *find_cost(t_stack *stk, int index_src, int index_dst, bool is_a_src)
{
	t_move *mv;

	mv = malloc(sizeof(t_move));
	if (!mv)
		return (NULL);
	mv->index_src = index_src;
	mv->index_dst = index_dst;
	mv->tmp = NULL;
	mv->cost = 0;
	if (is_a_src)
	{
		mv->len_in = stk->size_a;
		mv->len_out = stk->size_b;
	} else {
		mv->len_in = stk->size_b;
		mv->len_out = stk->size_a;
	}
	//ft_printf("index_src: %d,\tindex_dst: %d\n", index_src, index_dst);
	mv->src_go_up = should_go_up(index_src, mv->len_in);
	mv->dst_go_up = should_go_up(index_dst, mv->len_out);
	//ft_printf("src_go_up: %d,\tdst_go_up: %d\n", mv->src_go_up, mv->dst_go_up);
	get_gap(mv);
	//ft_printf("src_go_up: %d,\tdst_go_up: %d\t|\tgap_a: %d\tgap_b: %d\n", mv->src_go_up, mv->dst_go_up, mv->gap_a, mv->gap_b);
	if (mv->src_go_up == mv->dst_go_up && mv->src_go_up != NONE)
		handle_move_both_stack(mv);
	if (mv->src_go_up != NONE)
		handle_move_one_stack(mv, is_a_src, true);
	if (mv->dst_go_up != NONE)
		handle_move_one_stack(mv, !is_a_src, false);
    /* if (is_a_in)
        ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(PB));
    else
        ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(PA)); */
	//print_lst(&mv->tmp);
	return (mv->tmp);
}

void	find_target_and_push_low(t_stack *stack, t_list_stack *src, t_list_stack *dst)
{
	int				i;
	int				lowest_cost;
	int				lowest_cost_index;
	int				cost;
	t_list_stack	*tmp;
	t_list_stack	*lowest;

	i = 0;
	lowest_cost = 9999999;
	lowest_cost_index = -1;
	lowest = NULL;
	while (i < stack->size_a && src != NULL)
	{
		tmp = find_cost(stack, i, find_target_node_small(dst, src->content), true);
		cost = ft_lstsize_stack(tmp);
		if (cost < lowest_cost)
		{
			if (lowest != NULL)
				ft_lstclear_stack(&lowest);
			lowest_cost = cost;
			lowest_cost_index = i;
			lowest = tmp;
			if (cost == 0)
				break;
		}
		i++;
		src = src->next;
	}
	if (lowest_cost_index != -1)
	{
		ft_lstadd_back_stack(&lowest, ft_lstnew_stack(PB));
		perform_lst(&lowest, stack);
	}
}

bool	is_stack_sorted(t_list_stack *src)
{
	int		last;
	int		current;

	if (src == NULL)
		return (true);
	last = src->content;
	src = src->next;
	while (src)
	{
		current = src->content;
		//ft_printf("%d last: %d\tcurrent: %d\n", current < last, last, current);
		if (current < last)
			return (false);
		last = current;
		src = src->next;
	}
	return (true);
}

void	push_until_3_dest_stack(t_stack *stack, bool is_a_src)
{
	find_target_and_push_low(stack, stack->stack_a, stack->stack_b);
	if (stack->size_a > 3)
		return (push_until_3_dest_stack(stack, is_a_src));
	sort_stack_max_3(stack, is_a_src);
	return (push_until_finish(stack));
}
