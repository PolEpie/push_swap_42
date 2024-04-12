/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:49:58 by pepie             #+#    #+#             */
/*   Updated: 2024/03/19 14:28:43 by pepie            ###   ########.fr       */
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

int	initialisation(t_stack *stack, char *input)
{
	t_list_stack	*tmp;
	char			**inputs;

	inputs = ft_split(input, ' ');
	if (!inputs)
		return (1);
	stack->stack_a = ft_lstnew_stack(ft_atoi(*inputs));
	if (!stack->stack_a)
		return (1);
	stack->size_a = 1;
	tmp = stack->stack_a;
	inputs++;
	while (*inputs)
	{
		tmp->next = ft_lstnew_stack(ft_atoi(*inputs));
		if (!tmp->next)
			return (1);
		tmp = tmp->next;
		stack->size_a++;
		inputs++;
	}
	stack->stack_b = NULL;
	stack->size_b = 0;
	return (0);
}

char	*concat_input(int ac, char **av)
{
	char	*input;
	int		i;

	i = 1;
	input = ft_strdup(av[i]);
	if (!input)
		return (NULL);
	while (++i < ac)
	{
		input = ft_strjoin(input, " ");
		if (!input)
			return (NULL);
		input = ft_strjoin(input, av[i]);
		if (!input)
			return (NULL);
	}
	return (input);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*input;

	input = concat_input(ac, av);
	if (!input)
		return (ft_printf("Error\n"),1);
	if (!initialisation(&stack, input))
		return (ft_printf("Error\n"),1);
	//print_stacks(&stack);

	if (stack.size_a <= 3)
		return (sort_stack_max_3(&stack), 0);
	/* {
		sort_stack_max_3(&stack);
		print_stacks(&stack);
		return (0);
	} */

	pb(&stack);
	pb(&stack);
	print_operation(PB);
	print_operation(PB);
	//print_stacks(&stack);
    
    push_until_3_dest_stack(&stack);

	//print_stacks(&stack);

	//ft_printf("target node of #1: %d\n", find_target_node(stack.stack_b, stack.stack_a->next->next->next->content));
	return (0);
}

//https://www.youtube.com/watch?v=wRvipSG4Mmk&t=125s