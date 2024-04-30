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

void	perform_lst(t_list_s **lst, t_stack *stack)
{
	t_list_s	*tmp;

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

bool	is_stack_sorted(t_list_s *src)
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
		if (current < last)
			return (false);
		last = current;
		src = src->next;
	}
	return (true);
}

bool	push_until_3_dest_stack(t_stack *stack)
{
	find_target_and_push_low(stack, stack->stack_a, stack->stack_b);
	if (stack->size_a > 3)
		return (push_until_3_dest_stack(stack));
	sort_stack_max_3(stack);
	return (push_until_finish(stack));
}
