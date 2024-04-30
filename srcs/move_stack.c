/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:07:45 by pepie             #+#    #+#             */
/*   Updated: 2024/04/30 15:18:25 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_move_both_stack(t_move *mv)
{
	int	i;
	int	gap;

	i = 0;
	if (mv->src_go_up == UP || mv->src_go_up == DOWN)
	{
		gap = ft_mathmin(mv->gap_a, mv->gap_b);
		while (i < gap)
		{
			mv->cost++;
			if (mv->src_go_up == UP)
				ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(RR));
			else
				ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(RRA));
			i++;
		}
		mv->gap_a -= gap;
		mv->gap_b -= gap;
	}
	return (0);
}

static int	get_gap(t_move *mv, bool is_src)
{
	if (is_src)
		return (mv->gap_a);
	return (mv->gap_b);
}

void	handle_move_one_stack(t_move *mv, bool is_a_in, bool is_src)
{
	int	i;
	int	gap;
	int	dir;
	int	op;

	i = 0;
	gap = get_gap(mv, is_src);
	if (is_src)
		dir = mv->src_go_up;
	else
		dir = mv->dst_go_up;
	if (dir == UP)
		op = RA;
	else if (dir == DOWN)
		op = RRA;
	else
		return ;
	if (!is_a_in)
		op += 1;
	while (i < gap)
	{
		ft_lstadd_back_stack(&mv->tmp, ft_lstnew_stack(op));
		mv->cost = mv->cost + 1;
		i++;
	}
}
