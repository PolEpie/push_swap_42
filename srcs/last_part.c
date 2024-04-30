/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:23:17 by pepie             #+#    #+#             */
/*   Updated: 2024/04/30 15:32:46 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_lowest_cost {
	int				i;
	int				lowest_cost;
	int				lowest_cost_index;
	int				cost;
	t_list_s		*tmp_sol;
	t_list_s		*tmp_stk;
}	t_lowest_cost;

int	get_lowest_cost(t_stack *stack, t_list_s *src, t_list_s *dst, t_list_s *low)
{
	t_lowest_cost	inf;

	inf.i = 0;
	inf.lowest_cost = 9999999;
	inf.lowest_cost_index = -1;
	inf.tmp_stk = src;
	while (inf.tmp_stk != NULL)
	{
		inf.tmp_sol = find_cost(stack, inf.i,
				find_target_node_big(dst, src->content), false);
		inf.cost = ft_lstsize_stack(inf.tmp_sol);
		if (inf.cost < inf.lowest_cost)
		{
			if (low != NULL)
				ft_lstclear_stack(&low);
			inf.lowest_cost = inf.cost;
			inf.lowest_cost_index = inf.i;
			low = inf.tmp_sol;
		}
		inf.tmp_stk = inf.tmp_stk->next;
		inf.i = inf.i + 1;
	}
	return (inf.lowest_cost_index);
}

bool	find_target_and_push_big(t_stack *stack, t_list_s *src, t_list_s *dst)
{
	t_list_s		*lowest;

	lowest = NULL;
	ft_printf("%d", get_lowest_cost(stack, src, dst, lowest));
	src = src->next;
	if (!ft_lstadd_back_stack(&lowest, ft_lstnew_stack(PA)))
		return (false);
	perform_lst(&lowest, stack);
	return (true);
}

bool	push_until_finish(t_stack *stack)
{
	if (stack->size_b == 0)
	{
		print_stacks(stack);
		//sort_stack_with_rotation(stack);
		return (true);
	}

		print_stacks(stack);
	if (!find_target_and_push_big(stack, stack->stack_b, stack->stack_a))
		return (false);
	push_until_finish(stack);
	return (true);
}
