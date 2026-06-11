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
		if (small->value > lst->value)
		{
			small = lst;
			index_min = index;
		}
		++index;
		lst = lst->next;
	}
	return (index_min);
}

void	insertion(t_list **lsta, t_list **lstb)
{
	int	i;
	int	lstsize;

	lstsize = ft_lstsize(*lsta);
	while (*lsta)
	{
		i = find_small(*lsta);
		if (i <= lstsize / 2)
		{
			while (i-- > 0)
				rotate_a(lsta);
		}
		else
		{
			while (i++ < lstsize)
				reverse_rotate_a(lsta);
		}
		push(lsta, lstb, 'b');
		lstsize--;
	}
	while (*lstb)
		push(lstb, lsta, 'a');
}
