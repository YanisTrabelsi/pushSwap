/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 00:48:48 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/23 05:12:20 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lstswap(t_list *lst)
{
	t_list	*next_node;
	t_list	*prev_node;
	t_list	*temp;

	next_node = lst->next;
	prev_node = NULL;
	if (lst->prev)
	{
		prev_node = lst->prev;
		prev_node->next = next_node;
	}
	temp = next_node->next;
	next_node->next = lst;
	lst->next = temp;
	if (temp)
		temp->prev = lst;
	temp = lst->prev;
	lst->prev = next_node;
	next_node->prev = temp;
}
