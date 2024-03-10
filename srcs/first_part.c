/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:26:56 by pepie             #+#    #+#             */
/*   Updated: 2024/03/10 02:26:56 by pepie            ###   ########.fr       */
/*                                                                            */
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
	if (target_len > 3)
		push_until_3_dest_stack(stack, is_a);
	return ;
}


void	push_until_3_dest_stack(t_stack *stack, bool is_a)
{
	t_list_stack	*tmp;
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
		tmp = stack->stack_a;
	}
	else
	{
		target_len = stack->size_b;
		tmp = stack->stack_b;
	}
	while (i < target_len)
	{
		cost = find_target_node(tmp, tmp->content);
		if (cost == 0)
			return case_0_cost(stack, is_a, target_len);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			lowest_cost_index = i;
		}
		ft_printf("ra\n");
		i++;
	}
	if (target_len > 3)
		push_until_3_dest_stack(stack, is_a);
}
