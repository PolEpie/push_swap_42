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

int	ft_lstsize_stack(t_list_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear_stack(t_list_stack **lst)
{
	t_list_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_lstlast_content(t_list_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst->content);
}

int ft_lstgetindex_stack(t_list_stack *lst, int index)
{
	int i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst->content);
		lst = lst->next;
		i++;
	}
	return (-1);
}