/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:49:58 by pepie             #+#    #+#             */
/*   Updated: 2024/03/10 00:49:58 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	t_list_stack	*tmp1;
	t_list_stack	*tmp2;
	int				i;

	tmp1 = stack->stack_a;
	tmp2 = stack->stack_b;
	i = 0;
	ft_printf("------- A ----- B\n");
	while (tmp1 || tmp2)
	{
		ft_printf("#%d\t", i);
		if (tmp1)
		{
			ft_printf("%d\t", tmp1->content);
			tmp1 = tmp1->next;
		}
		else
		ft_printf("x\t");
		if (tmp2)
		{
			ft_printf("%d\n", tmp2->content);
			tmp2 = tmp2->next;
		}
		else
			ft_printf("x\n");
		i++;
	}
	ft_printf("-----------------\n");
}

t_list_stack	*ft_lstnew_stack(int content)
{
	t_list_stack	*new;

	new = (t_list_stack *)malloc(sizeof(t_list_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	initialisation(t_stack *stack, int ac, char **av)
{
	t_list_stack	*tmp;
	int	i;

	i = 1;
	stack->stack_a = ft_lstnew_stack(ft_atoi(av[i]));
	stack->size_a = 1;
	tmp = stack->stack_a;
	while (++i < ac)
	{
		tmp->next = ft_lstnew_stack(ft_atoi(av[i]));
		tmp = tmp->next;
		stack->size_a++;
	}
	stack->stack_b = NULL;
	stack->size_b = 0;
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack	stack;
	initialisation(&stack, ac, av);
	print_stacks(&stack);
	pb(&stack);
	pb(&stack);
	print_stacks(&stack);
	ft_printf("target node of #1: %d\n", find_target_node(stack.stack_b, stack.stack_a->next->content));
	return (0);
}

//https://www.youtube.com/watch?v=wRvipSG4Mmk&t=125s