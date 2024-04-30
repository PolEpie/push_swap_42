/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:40:49 by pepie             #+#    #+#             */
/*   Updated: 2024/04/30 12:41:04 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_list_s *stack, int number)
{
	int			target_index;
	int			target_value;
	int			target_diff;
	int			i;

	target_index = -1;
	target_value = 0;
	target_diff = 9999999;
	i = 0;
	while (stack)
	{
		if (stack->content >= number && (stack->content - number < target_diff
				|| target_index == -1))
		{
			target_index = i;
			target_value = stack->content;
			target_diff = stack->content - number;
		}
		stack = stack->next;
		i++;
	}
	return (target_index);
}

static int	find_smallest(t_list_s *stack)
{
	int			target_index;
	int			target_value;
	int			i;

	target_index = -1;
	target_value = 0;
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
	return (target_index);
}

int	find_target_node_big(t_list_s *stack, int number)
{
	t_list_s	*tmp;
	int			i;
	int			target_index;

	tmp = stack;
	i = 0;
	target_index = find_biggest(stack, number);
	if (target_index == -1)
	{
		target_index = find_smallest(stack);
	}
	return (target_index);
}
