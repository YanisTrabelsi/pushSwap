/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:15:35 by lherpet           #+#    #+#             */
/*   Updated: 2026/06/03 18:15:40 by lherpet          ###   ########.fr       */
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

static void	insertion_max(t_list **lsta, t_list **lstb)
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
				rotate(lstb);
		}
		else
		{
			while (i++ < lstsize)
				reverse_rotate(lstb);
		}
		push(lstb, lsta, 'b');
		lstsize--;
	}
}

// ESSAI NORMINETTE
void	ft_reverse_rotate_chunk()
{
	rank_value = temp->rank;
	while (*lst_a && ft_lstlast(*lst_a)->rank != rank_value)
		reverse_rotate(lst_a);
	reverse_rotate(lst_a);
	push(lst_a, lst_b, 'a');
}

void	ft_rotate_chunk()
{
	rank_value = temp->rank;
	while (*lst_a && (*lst_a)->rank != rank_value)
		rotate(lst_a);
	push(lst_a, lst_b, 'a');
}

ft_chunk_sort_mid()
{
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
			reverse_rotate(lst_a);
		reverse_rotate(lst_a);
		push(lst_a, lst_b, 'a');
	}
	else
	{
		rank_value = temp->rank;
		while (*lst_a && (*lst_a)->rank != rank_value)
			rotate(lst_a);
		push(lst_a, lst_b, 'a');
	}
	if (*lst_b && (*lst_b)->rank < chunk_mid)
		rotate(lst_b);
	i = 0;
	nb_push++;
	lst_size--;
}

void	ft_chunk_sort(t_list **lst_a, t_list **lst_b, int chunk_size, int nb_chunk)
{
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
					reverse_rotate(lst_a);
				reverse_rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			else
			{
				rank_value = temp->rank;
				while (*lst_a && (*lst_a)->rank != rank_value)
					rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			if (*lst_b && (*lst_b)->rank < chunk_mid)
				rotate(lst_b);
			i = 0;
			nb_push++;
			lst_size--;
		}
		mult++;
	}
}
// ESSAI NORMINETTE

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

	normalise(*lst_a);
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
					reverse_rotate(lst_a);
				reverse_rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			else
			{
				rank_value = temp->rank;
				while (*lst_a && (*lst_a)->rank != rank_value)
					rotate(lst_a);
				push(lst_a, lst_b, 'a');
			}
			if (*lst_b && (*lst_b)->rank < chunk_mid)
				rotate(lst_b);
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
	insertion_max(lst_a, lst_b);
	//printf ("pa:%d\npb:%d\nrra:%d\nrrb:%d\nra:%d\nrb:%d\n", count->pa, count->pb, count->rra, count->rrb, count->ra, count->rb);
	//free(count);
}
