/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:26:56 by pepie             #+#    #+#             */
/*   Updated: 2024/04/30 13:46:20 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_lstadd_back_stack(t_list_s **lst, t_list_s *new)
{
	t_list_s	*last;

	if (!*lst)
	{
		*lst = new;
		return (true);
	}
	last = ft_lstlast_stack(*lst);
	if (last == NULL)
		return (false);
	last->next = new;
	return (true);
}

t_list_s	*ft_lstnew_stack(int content)
{
	t_list_s	*new;

	new = malloc(sizeof(t_list_s));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list_s	*ft_lstlast_stack(t_list_s *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_stack(t_list_s *lst)
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

void	ft_lstclear_stack(t_list_s **lst)
{
	t_list_s	*tmp;

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
