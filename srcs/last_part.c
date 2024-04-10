/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_past.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:23:17 by pepie             #+#    #+#             */
/*   Updated: 2024/04/10 20:23:17 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		find_target_node_big(t_list_stack *stack, int number)
{
	t_list_stack	*tmp;
	int				i;
	int				target_index;
	int				target_value;
	int				target_diff;

	tmp = stack;
	i = 0;
	target_index = -1;
	target_value = 0;
	target_diff = 9999999;
	while (stack)
	{
		if (stack->content >= number && (stack->content - number < target_diff || target_index == -1))
		{
			target_index = i;
			target_value = stack->content;
			target_diff = stack->content - number;
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
			if (stack->content < target_value || target_index == -1)
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


void	find_target_and_push_big(t_stack *stack, t_list_stack *src, t_list_stack *dst)
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

	tmp = find_cost(stack, i, find_target_node_big(dst, src->content), false);
	//ft_printf("%d\t\ttarget node: %d\t%d\n", src->content, find_target_node_big(dst, src->content), ft_lstsize_stack(tmp));
	
	cost = ft_lstsize_stack(tmp);
	//ft_printf("cost: %d\n", cost);
	if (cost < lowest_cost)
	{
		if (lowest != NULL)
			ft_lstclear_stack(&lowest);
		lowest_cost = cost;
		lowest_cost_index = i;
		lowest = tmp;
	}
	i++;
	src = src->next;
	
	if (lowest_cost_index != -1)
	{
		ft_lstadd_back_stack(&lowest, ft_lstnew_stack(PA));
		perform_lst(&lowest, stack);
	}
}

void	push_until_finish(t_stack *stack)
{
	if (stack->size_b == 0)
	{
		sort_stack_with_rotation(stack);
		//print_stacks(stack);
		return ;
	}
	find_target_and_push_big(stack, stack->stack_b, stack->stack_a);
	return (push_until_finish(stack));
}
