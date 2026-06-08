/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:58:58 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/27 18:58:58 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_small(t_list *lst)
{
	int		index;
	int		index_min;
	t_list	*small;

	index = 0;
	index_min = 0;
	small = lst;
	while (lst)
	{
		++index;
		if (small->value > lst->value)
		{
			small = lst;
			index_min = index;
		}
		lst = lst->next;
	}
	return (index_min - 1);
}

void	insertion(t_list **lsta, t_list **lstb)
{
	int		i;

	while (*lsta)
	{
		i = find_small(*lsta);
		while (i > 0)
		{
			rotate_a(lsta);
			--i;
		}
		push(lsta, lstb, 'a');
	}
	while (*lstb)
	{
		push(lstb, lsta, 'b');
	}
}
