/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:12:46 by pepie             #+#    #+#             */
/*   Updated: 2024/03/10 01:12:46 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list_stack	*tmp;
	t_list_stack	*last;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a;
	last = stack->stack_a;
	while (last->next)
		last = last->next;
	stack->stack_a = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rb(t_stack *stack)
{
	t_list_stack	*tmp;
	t_list_stack	*last;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b;
	last = stack->stack_b;
	while (last->next)
		last = last->next;
	stack->stack_b = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

void	rra(t_stack *stack)
{
	t_list_stack	*tmp;
	t_list_stack	*last;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->stack_a;
	stack->stack_a = last;
}

void	rrb(t_stack *stack)
{
	t_list_stack	*tmp;
	t_list_stack	*last;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->stack_b;
	stack->stack_b = last;
}
