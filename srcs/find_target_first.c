/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:15:32 by pepie             #+#    #+#             */
/*   Updated: 2024/04/30 11:17:43 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_list_s *stack, int number)
{
	int			target_index;
	int			target_value;
	int			i;

	target_index = -1;
	target_value = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < number && (stack->content > target_value
				|| target_index == -1))
		{
			target_index = i;
			target_value = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (target_index);
}

static int	find_biggest(t_list_s *stack)
{
	int			target_index;
	int			target_value;
	int			i;

	target_index = -1;
	target_value = 0;
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
	return (target_index);
}

int	find_target_node_small(t_list_s *stack, int number)
{
	int			target_index;

	target_index = find_smallest(stack, number);
	if (target_index == -1)
	{
		target_index = find_biggest(stack);
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

void	free_error(char **split, char **split_free, t_stack *stack)
{
	ft_freesplit(split);
	free(split_free);
	ft_lstclear_stack(&stack->stack_a);
}
