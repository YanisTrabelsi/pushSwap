/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:31:20 by ytrabels          #+#    #+#             */
/*   Updated: 2026/06/05 14:31:20 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	bit_check(t_list **lst_a, t_list **lst_b)
{
	t_list	*head;

	head = *lst_a;
	while (head)
	{
		if (head->rank & 1)
			rotate(lst_a);
		else
			push(lst_a, lst_b, 'b');
		head = head->next;
	}
}

void	radix(t_list **lst_a, t_list **lst_b)
{
	(void)lst_b;
	normalise(*lst_a);
	bit_check(lst_a, lst_b);
	printf("bit check done\n");
}
