/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:22:57 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/23 01:40:03 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	bubble(t_list *lst_a)
{
	t_list	*head;

	head = lst_a;
	while(lst_a)
	{
		printf("%d\n", lst_a->value);
		if (lst_a->prev)
			printf("%d\n", lst_a->prev->value);
		if (lst_a->next && lst_a->value > lst_a->next->value)
		{
			ft_lstswap(lst_a);
			printf("swapped\n");
			lst_a = head;
		}
		else
			lst_a = lst_a->next;
	}
}
