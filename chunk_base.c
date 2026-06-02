/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:46:46 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/29 14:46:54 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_list *lst)
{
	int		index;
	int		index_max;
	t_list	*max;

	index = 0;
	index_max = 0;
	max = lst;
	while (lst)
	{
		index++;
		if (max->value < lst->value)
		{
			max = lst;
			index_max = index;
		}
		lst = lst->next;
	}
	return (index_max);
}

static void	insertion_max(t_list **lsta, t_list **lstb)
{
	int		i;

	while (*lstb)
	{
		i = find_max(*lstb);
		while (i > 0)
		{
			if (i > ft_lstsize(*lstb)/2)
			{
				rotate(lstb);
				i--;
			}
			else
			{
				reverse_rotate(lstb);
				i--;
			}
		}
		push(lstb, lsta, 'b');
	}
}

void	chunk_base(t_list **lst_a, t_list **lst_b)
{
	int	lst_size;
	int	nb_chunk;
	int	i;
	int	mult;
	int	rank_value;
	int	nb_push;
	t_list	*temp;

	normalise(lst_a);
	i = 0;
	mult = 1;
	nb_push = 0;
	lst_size = ft_lstsize(*lst_a);
	if (lst_size <= 100)
		nb_chunk = 5;
	else
		nb_chunk = 11;
	while(*lst_a)
	{
		while (nb_push <= (lst_size/nb_chunk) * mult)
		{
			temp = *lst_a;
			while (temp && (temp) -> rank > (lst_size/nb_chunk) * mult)
			{
				temp = temp -> next;
				i++;
			}
			if (i > ft_lstsize(*lst_a)/2)
			{
				rank_value = (*lst_a) -> rank;
				while (*lst_a && ft_lstlast(*lst_a) -> rank != rank_value)
					reverse_rotate(lst_a);
				reverse_rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			else
			{
				rank_value = (*lst_a) -> rank;
				while (*lst_a && (*lst_a) -> rank != rank_value)
					rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			nb_push++;
		}
		mult++;
	}
	insertion_max(lst_a, lst_b);
}
