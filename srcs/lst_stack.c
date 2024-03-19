/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:26:56 by pepie             #+#    #+#             */
/*   Updated: 2024/03/19 14:27:46 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_stack(t_list_stack **lst, t_list_stack *new)
{
	t_list_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_stack(*lst);
	if (last == NULL)
		return ;
	last->next = new;
}

t_list_stack	*ft_lstnew_stack(int content)
{
    t_list_stack	*new;

    new = malloc(sizeof(t_list_stack));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

t_list_stack   *ft_lstlast_stack(t_list_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}