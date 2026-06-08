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
/*void	ft_reverse_rotate_chunk()
{
	while (*lst_a && ft_lstlast(*lst_a)->rank != rank_value)
		reverse_rotate(lst_a);
	reverse_rotate(lst_a);
}

void	ft_rotate_chunk()
{
	while (*lst_a && (*lst_a)->rank != rank_value)
		rotate(lst_a);
	push(lst_a, lst_b, 'a');
}*/

static void	ft_push_elem(t_list **lst_a, t_list **lst_b, int chunk_mid, int chunk_max_rank)
{
	int		i;
	int		rank_value;
	t_list	*temp;

	i = 0;
	temp = *lst_a;
	while (temp && temp->rank > chunk_max_rank)
	{
		temp = temp->next;
		i++;
	}
	if (!temp)
		return ;
	rank_value = temp->rank;
	if (i > ft_lstsize(*lst_a) / 2)
	{
		while (*lst_a && ft_lstlast(*lst_a)->rank != rank_value)
			reverse_rotate(lst_a);
		reverse_rotate(lst_a);
	}
	else
	{
		while (*lst_a && (*lst_a)->rank != rank_value)
			rotate(lst_a);
	}
	push(lst_a, lst_b, 'a');
	if (*lst_b && (*lst_b)->rank < chunk_mid)
		rotate(lst_b);
}

static void	ft_chunkbase_loop(t_list **lst_a, t_list **lst_b, int chunk_size, int nb_chunk)
{
	int	mult;
	int	nb_push;
	int	chunk_mid;
	int	lst_size;

	mult = 1;
	nb_push = 0;
	lst_size = ft_lstsize(*lst_a);
	while (mult <= nb_chunk + 1)
	{
		chunk_mid = chunk_size * (mult - 1) + (chunk_size / 2) + 1;
		while (nb_push < chunk_size * mult && *lst_a)
		{
			ft_push_elem(lst_a, lst_b, chunk_mid, chunk_size * mult);
			nb_push++;
			lst_size--;
		}
		mult++;
	}
}

void	chunk_base(t_list **lst_a, t_list **lst_b)
{
	int	initial_size;
	int	nb_chunk;
	int	chunk_size;

	normalise(*lst_a);
	initial_size = ft_lstsize(*lst_a);
	if (initial_size <= 100)
		nb_chunk = 5;
	else
		nb_chunk = 11;
	chunk_size = initial_size / nb_chunk;
	ft_chunkbase_loop(lst_a, lst_b, chunk_size, nb_chunk);
	insertion_max(lst_a, lst_b);
}
