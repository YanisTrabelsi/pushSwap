/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:09:14 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/25 15:09:16 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_list	**lst)
{
	t_list	*next_node;
	t_list	*temp;

	if (!(*lst) || (*lst)->next == NULL)
		return ;
	next_node = (*lst)->next;
	temp = next_node->next;
	next_node->next = *lst;
	(*lst)->next = temp;
	if (temp)
		temp->prev = *lst;
	temp = (*lst)->prev;
	(*lst)->prev = next_node;
	next_node->prev = temp;
	*lst = next_node;
}

void	push(t_list	**lst_from, t_list	**lst_to, char c)
{
	(void)c;
	ft_lstadd_front(lst_to, ft_lstnew((*lst_from)->value, (*lst_from)->rank));
	ft_lstdelfront(lst_from);
}

void	rotate(t_list	**lst)
{
	ft_lstadd_back(lst, ft_lstnew((*lst)->value, (*lst)->rank));
	ft_lstdelfront(lst);
}

void	reverse_rotate(t_list	**lst)
{
	t_list	*temp;

	ft_lstadd_front(lst, ft_lstnew(ft_lstlast(*lst)->value,
			ft_lstlast(*lst)->rank));
	temp = ft_lstlast(*lst);
	if (temp -> prev)
		temp -> prev -> next = NULL;
	free (temp);
}
