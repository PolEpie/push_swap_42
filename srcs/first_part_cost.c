/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:55:55 by pepie             #+#    #+#             */
/*   Updated: 2024/05/01 11:37:04 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_direction	should_go_up(int index, int size)
{
	if (index == 0)
		return (NONE);
	else if (index <= size / 2)
		return (UP);
	else
		return (DOWN);
}

void	get_gap(t_move *mv)
{
	if (mv->src_go_up == UP)
		mv->gap_a = mv->index_src;
	else if (mv->src_go_up == DOWN)
		mv->gap_a = mv->len_in - mv->index_src;
	else
		mv->gap_a = 0;
	if (mv->dst_go_up == UP)
		mv->gap_b = mv->index_dst;
	else if (mv->dst_go_up == DOWN)
		mv->gap_b = mv->len_out - mv->index_dst;
	else
		mv->gap_b = 0;
}

void	init_mv(t_move *mv, t_stack *stk, bool is_a_src, int i_src)
{
	mv->index_src = i_src;
	mv->tmp = NULL;
	mv->cost = 0;
	if (is_a_src)
	{
		mv->len_in = stk->size_a;
		mv->len_out = stk->size_b;
	}
	else
	{
		mv->len_in = stk->size_b;
		mv->len_out = stk->size_a;
	}
	mv->src_go_up = should_go_up(i_src, mv->len_in);
}

t_list_s	*find_cost(t_stack *stk, int i_src, int index_dst, bool is_a_src)
{
	t_move		*mv;
	t_list_s	*tmp;

	mv = malloc(sizeof(t_move));
	if (!mv)
		return (NULL);
	mv->index_dst = index_dst;
	init_mv(mv, stk, is_a_src, i_src);
	mv->dst_go_up = should_go_up(index_dst, mv->len_out);
	get_gap(mv);
	if (mv->src_go_up == mv->dst_go_up && mv->src_go_up != NONE)
		handle_move_both_stack(mv);
	if (mv->src_go_up != NONE)
		handle_move_one_stack(mv, is_a_src, true);
	if (mv->dst_go_up != NONE)
		handle_move_one_stack(mv, !is_a_src, false);
	tmp = mv->tmp;
	free(mv);
	return (tmp);
}
