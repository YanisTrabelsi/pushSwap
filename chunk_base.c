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
		if (max->rank < lst->rank)
		{
			max = lst;
			index_max = index;
		}
		lst = lst->next;
		index++;
	}
	return (index_max);
}

static void	insertion_max(t_list **lsta, t_list **lstb, t_bench *count)
{
	int	i;
	int	lstsize;

	lstsize = ft_lstsize(*lstb);
	while (*lstb)
	{
		i = find_max(*lstb);
		if (i <= lstsize / 2)
		{
			while (i-- > 0)
			{
				rotate(lstb);
				count->rb = count->rb + 1;
			}
		}
		else
		{
			while (i++ < lstsize)
			{
				reverse_rotate(lstb);
				count->rrb = count->rrb + 1;
			}
		}
		push(lstb, lsta, 'b');
		count->pb = count->pb + 1;
		lstsize--;
	}
}

void	chunk_base(t_list **lst_a, t_list **lst_b)
{
	int	lst_size;
	int	initial_size;
	int	nb_chunk;
	int	chunk_size;
	int	chunk_mid;
	int	i;
	int	mult;
	int	rank_value;
	int	nb_push;
	t_list	*temp;
	t_bench	*count;

	normalise(*lst_a);
	count = malloc(sizeof(t_bench));
	if (!count)
		return ;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->pa = 0;
	count->pb = 0;
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	i = 0;
	mult = 1;
	nb_push = 0;
	initial_size = ft_lstsize(*lst_a);
	lst_size = initial_size;
	if (lst_size <= 100)
		nb_chunk = 5;
	else
		nb_chunk = 11;
	chunk_size = initial_size / nb_chunk;
	while (mult <= nb_chunk + 1)
	{
		chunk_mid = chunk_size * (mult - 1) + (chunk_size / 2) + 1;
		while (nb_push < chunk_size * mult)
		{
			temp = *lst_a;
			while (temp && temp->rank > chunk_size * mult)
			{
				temp = temp->next;
				i++;
			}
			if (!temp)
				i = 0;
			else if (i > lst_size / 2)
			{
				rank_value = temp->rank;
				while (*lst_a && ft_lstlast(*lst_a)->rank != rank_value)
				{
					reverse_rotate(lst_a);
					count->rra = count->rra + 1;
				}
				reverse_rotate(lst_a);
				count->rra = count->rra + 1;
				push(lst_a, lst_b, 'a');
				count->pa = count->pa + 1;
			}
			else
			{
				rank_value = temp->rank;
				while (*lst_a && (*lst_a)->rank != rank_value)
				{
					rotate(lst_a);
					count->ra = count->ra + 1;
				}
				push(lst_a, lst_b, 'a');
				count->pa = count->pa + 1;
			}
			if (*lst_b && (*lst_b)->rank < chunk_mid)
			{
				rotate(lst_b);
				count->rb = count->rb + 1;
			}
			i = 0;
			nb_push++;
			lst_size--;
		}
		mult++;
	}
	/*
	// DEBUG
	temp = *lst_b;
	printf("||| LST_B |||\n");
	while(temp)
	{
		printf("||| %d |||\n", temp->value);
		temp = temp->next;
	}
	// DEBUG
	*/
	insertion_max(lst_a, lst_b, count);
	printf ("pa:%d\npb:%d\nrra:%d\nrrb:%d\nra:%d\nrb:%d\n", count->pa, count->pb, count->rra, count->rrb, count->ra, count->rb);
	free(count);
}
