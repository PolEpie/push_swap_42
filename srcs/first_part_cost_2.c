/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:55:55 by pepie             #+#    #+#             */
/*   Updated: 2024/05/01 11:37:04 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_find_target {
	int				i;
	int				lowest_cost;
	int				lowest_cost_index;
}	t_find_target;

t_list_s	*calculate_cost_for_i(t_stack *stack, int index_src)
{
	t_list_s	*lowest;
	t_list_s	*tmp;
	int			i;
	int			value;

	tmp = stack->stack_a;
	i = 0;
	while (i < index_src)
	{
		tmp = tmp->next;
		i++;
	}
	value = tmp->content;
	lowest = find_cost(stack, index_src,
			find_target_node_small(stack->stack_b, value), true);
	ft_lstadd_back_stack(&lowest, ft_lstnew_stack(PB));
	return (lowest);
}

void	find_target_and_push_low(t_stack *stack)
{
	t_list_s		*lowest;
	t_list_s		*tmp;
	int				lowest_cost;
	int				i;

	i = 0;
	lowest_cost = 99999999;
	tmp = NULL;
	lowest = NULL;
	while (i < stack->size_a)
	{
		tmp = calculate_cost_for_i(stack, i);
		if (ft_lstsize_stack(tmp) < lowest_cost)
		{
			lowest_cost = ft_lstsize_stack(tmp);
			if (lowest)
				ft_lstclear_stack(&lowest);
			lowest = tmp;
		}
		else
			ft_lstclear_stack(&tmp);
		i++;
	}
	perform_lst(&lowest, stack);
}
