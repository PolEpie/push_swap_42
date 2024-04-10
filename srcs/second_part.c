/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:18:03 by pepie             #+#    #+#             */
/*   Updated: 2024/04/10 15:18:03 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_higher_pos(t_list_stack *lst)
{
	int		higher;
	int		pos;
	int		i;

	higher = lst->content;
	pos = 0;
	i = 0;
	while (lst)
	{
		if (lst->content > higher)
		{
			higher = lst->content;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

void	sort_2_el(t_stack *stack, bool is_a, t_list_stack *to_sort)
{
	if (ft_lstgetindex_stack(to_sort, 0) > ft_lstgetindex_stack(to_sort, 1))
	{
		if (is_a)
		{
			sa(stack);
			print_operation(SA);
		}
		else
		{
			sb(stack);
			print_operation(SB);
		}
	}
}

void	sort_stack(t_stack *stack, bool is_a)
{
	t_list_stack	*to_sort;

	if (is_a)
		to_sort = stack->stack_a;
	else
		to_sort = stack->stack_b;
	//ft_printf("drgr %d:\n", get_stack_higher_pos(to_sort));
	if (get_stack_higher_pos(to_sort) == 2)
	{
		sort_2_el(stack, is_a, to_sort);
	}
	else if (get_stack_higher_pos(to_sort) == 1)
	{
		if (is_a)
			ra(stack);
		else
			rb(stack);
	}
	else if (get_stack_higher_pos(to_sort) == 0)
	{
		if (is_a)
			rra(stack);
		else
			rrb(stack);
	}
	sort_2_el(stack, is_a, to_sort);
}