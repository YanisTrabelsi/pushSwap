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

void	swap_a(t_list **lst, int c)
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
	//if (c == 0)
	//	printf("sa\n");
}

void	swap_b(t_list **lst, int c)
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
	//if (c == 0)
	//	printf("sb\n");
}

void	swap_swap(t_list **lst_a, t_list **lst_b)
{
	swap_a(lst_a, '1');
	swap_b(lst_b, '1');
	//printf("ss\n");
}


void	push(t_list **lst_from, t_list **lst_to, char c)
{
	(void)c;
	ft_lstadd_front(lst_to, ft_lstnew((*lst_from)->value, (*lst_from)->rank));
	ft_lstdelfront(lst_from);
	//printf("p%c\n", c);
	//if (c == 'a')
	//	...pa;
	//else if (c == 'b')
	//	...pb;
}

void	reverse_rotate_rotate(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	ft_lstadd_front(lst_a, ft_lstnew(ft_lstlast(*lst_a)->value, ft_lstlast(*lst_a)->rank));
	temp = ft_lstlast(*lst_a);
	if (temp -> prev)
		temp -> prev -> next = NULL;
	free (temp);
		ft_lstadd_front(lst_b, ft_lstnew(ft_lstlast(*lst_b)->value, ft_lstlast(*lst_b)->rank));
	temp = ft_lstlast(*lst_b);
	if (temp -> prev)
		temp -> prev -> next = NULL;
	free (temp);
	//printf("rrr\n")

}
