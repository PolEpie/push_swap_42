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

void   sort_stack_with_rotation(t_stack *stack)
{
	int		pos;
	int		size;
	if (is_stack_sorted(stack->stack_a))
		return ;
	pos = get_stack_higher_pos(stack->stack_a);
	size = ft_lstsize_stack(stack->stack_a);
	//ft_printf("pos = %d\n", pos);
	//print_stacks(stack);
	if (pos < size / 2)
	{
		ra(stack);
		print_operation(RA);
		sort_stack_with_rotation(stack);
	}
	else
	{
		rra(stack);
		print_operation(RRA);
		sort_stack_with_rotation(stack);
	}
}

void	sort_2_el(t_stack *stack)
{
	if (stack->size_a > 1 && ft_lstgetindex_stack(stack->stack_a, 0) > ft_lstgetindex_stack(stack->stack_a, 1))
	{
		sa(stack);
		print_operation(SA);
	}
}

void	sort_stack_max_3(t_stack *stack)
{
	t_list_stack	*to_sort;

	to_sort = stack->stack_a;
	if (get_stack_higher_pos(to_sort) == 2)
	{
		sort_2_el(stack);
	}
	else if (get_stack_higher_pos(to_sort) == 1)
	{
		rra(stack);
	}
	else if (get_stack_higher_pos(to_sort) == 0)
	{
		ra(stack);
	}
	//print_stacks(stack);
	sort_2_el(stack);
}