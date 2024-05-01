/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:12:46 by pepie             #+#    #+#             */
/*   Updated: 2024/05/01 13:04:41 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}

void	finish(t_stack *stack)
{
	ft_lstclear_stack(&stack->stack_a);
	ft_lstclear_stack(&stack->stack_b);
}
