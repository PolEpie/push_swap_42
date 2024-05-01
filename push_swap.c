/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:49:58 by pepie             #+#    #+#             */
/*   Updated: 2024/05/01 10:45:35 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_stacks(t_stack *stack)
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
} */

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
	while (tmp)
	{
		if (tmp->content == num)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	initialisation(t_stack *stack, char *input)
{
	t_list_s	*tmp;
	char		**inputs;

	inputs = ft_split(input, ' ');
	if (!inputs)
		return (1);
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
	i++;
	while (i < ac)
	{
		input = ft_strjoin(input, " ");
		if (!input)
			return (NULL);
		input = ft_strjoin(input, av[i]);
		if (!input)
			return (NULL);
		i++;
	}
	return (input);
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
	if (initialisation(&stack, input) == 1)
		return (write(2, "Error\n", 6), 1);
	if (stack.size_a <= 3)
		return (sort_stack_max_3(&stack), 0);
	if (is_stack_sorted(stack.stack_a))
		return (0);
	pb(&stack);
	pb(&stack);
	print_operation(PB);
	print_operation(PB);
	if (!push_until_3_dest_stack(&stack))
		return (write(2, "Error\n", 6), 1);
	return (0);
}

//https://www.youtube.com/watch?v=wRvipSG4Mmk&t=125s