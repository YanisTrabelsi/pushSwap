/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 00:48:48 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/23 02:38:45 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lstswap(t_list *lst)
{
	t_list	*next_node;
	t_list	*temp;

	next_node = lst->next;
	temp = next_node->next;
	next_node->next = lst;
	lst->prev = next_node;
	lst->next = temp;
	next_node->prev = NULL;
}
