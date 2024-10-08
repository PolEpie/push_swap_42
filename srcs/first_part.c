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

void	perform_lst_part_2(int content, t_stack *stack)
{
	if (content == RR)
		rr(stack);
	else if (content == RRA)
		rra(stack);
	else if (content == RRB)
		rrb(stack);
	else if (content == RRR)
		rrr(stack);
	else if (content == RB)
		rb(stack);
	else if (content == RA)
		ra(stack);
}

void	perform_lst(t_list_s **lst, t_stack *stack)
{
	t_list_s	*tmp;
	t_list_s	*old;

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
		else
			perform_lst_part_2(tmp->content, stack);
		print_operation(tmp->content);
		old = tmp;
		tmp = tmp->next;
		free(old);
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
	find_target_and_push_low(stack);
	if (stack->size_a > 3)
		return (push_until_3_dest_stack(stack));
	sort_stack_max_3(stack);
	return (push_until_finish(stack));
}
