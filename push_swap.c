/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:49:58 by pepie             #+#    #+#             */
/*   Updated: 2024/05/01 12:01:44 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	t_list_s	*tmp1;
	t_list_s	*tmp2;
	int			i;

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

bool	is_number_valid(char *str)
{
	int			i;
	int			minus_count;
	bool		is_numeric;

	i = 0;
	minus_count = 0;
	is_numeric = false;
	while (str[i])
	{
		if (str[i] == '-')
		{
			minus_count++;
			i++;
		}
		else if ((str[i] >= '0' && str[i] <= '9'))
		{
			is_numeric = true;
			i++;
		}
		else
			return (false);
	}
	return (minus_count <= 1 && is_numeric);
}

bool	is_numeric(char *str, t_list_s **s)
{
	t_list_s	*tmp;
	long		num;

	if (!is_number_valid(str))
		return (false);
	tmp = *s;
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	if (s && tmp)
	{
		while (tmp)
		{
			if (tmp->content == num)
				return (false);
			tmp = tmp->next;
		}
	}
	return (true);
}

int	initialisation(t_stack *stack, char *input)
{
	t_list_s	*tmp;
	char		**inputs;
	char		**inputs_og;

	inputs = ft_split(input, ' ');
	if (!inputs)
		return (1);
	inputs_og = inputs;
	stack->size_a = 0;
	tmp = stack->stack_a;
	while (*inputs != NULL)
	{
		if (is_numeric(*inputs, &stack->stack_a) == false)
			return (1);
		if (!ft_lstadd_back_stack(&stack->stack_a,
				ft_lstnew_stack(ft_atoi(*inputs))))
			return (1);
		stack->size_a++;
		free(*inputs);
		inputs++;
	}
	free(inputs_og);
	stack->size_b = 0;
	free(input);
	return (0);
}

char	*concat_input(int ac, char **av)
{
	char	*input;
	char	*tmp;
	int		i;

	i = 1;
	input = ft_strdup(av[i]);
	if (!input)
		return (NULL);
	i++;
	while (i < ac)
	{
		tmp = ft_strjoin(input, " ");
		free(input);
		input = tmp;
		if (!input)
			return (NULL);
		tmp = ft_strjoin(input, av[i]);
		free(input);
		input = tmp;
		if (!input)
			return (NULL);
		i++;
	}
	return (input);
}

void	finish(t_stack *stack)
{
	ft_lstclear_stack(&stack->stack_a);
	ft_lstclear_stack(&stack->stack_b);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*input;

	if (ac < 2)
		return (write(2, "Error\n", 6), 1);
	input = concat_input(ac, av);
	if (!input)
		return (write(2, "Error\n", 6), 1);
	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (initialisation(&stack, input) == 1)
		return (write(2, "Error\n", 6), 1);
	if (stack.size_a <= 3)
		return (sort_stack_max_3(&stack), finish(&stack), 0);
	if (is_stack_sorted(stack.stack_a))
		return (finish(&stack), 0);
	pb(&stack);
	pb(&stack);
	print_operation(PB);
	print_operation(PB);
	if (!push_until_3_dest_stack(&stack))
		return (finish(&stack), write(2, "Error\n", 6), 1);
	finish(&stack);
	return (0);
}

//https://www.youtube.com/watch?v=wRvipSG4Mmk&t=125s