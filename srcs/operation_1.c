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

void	sa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a->next;
	stack->stack_a->next = tmp->next;
	tmp->next = stack->stack_a;
	stack->stack_a = tmp;
}

void	sb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b->next;
	stack->stack_b->next = tmp->next;
	tmp->next = stack->stack_b;
	stack->stack_b = tmp;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_b == 0)
		return ;
	tmp = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	tmp->next = stack->stack_a;
	stack->stack_a = tmp;
	stack->size_a++;
	stack->size_b--;
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size_a == 0)
		return ;
	tmp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	tmp->next = stack->stack_b;
	stack->stack_b = tmp;
	stack->size_a--;
	stack->size_b++;
}
