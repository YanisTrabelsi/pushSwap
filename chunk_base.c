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

static void	ft_reverse_rotate_chunk(t_list **lst_a, int rank_value)
{
	while (*lst_a && ft_lstlast(*lst_a)->rank != rank_value)
		reverse_rotate(lst_a);
	reverse_rotate(lst_a);
}

static void	push_elem(t_list **lst_a, t_list **lst_b, int c_mid, int c_max)
{
	int		i;
	int		rank_value;
	t_list	*temp;

	i = 0;
	temp = *lst_a;
	while (temp && temp->rank > c_max)
	{
		temp = temp->next;
		i++;
	}
	if (!temp)
		return ;
	rank_value = temp->rank;
	if (i > ft_lstsize(*lst_a) / 2)
		ft_reverse_rotate_chunk(lst_a, rank_value);
	else
	{
		while (*lst_a && (*lst_a)->rank != rank_value)
			rotate(lst_a);
	}
	push(lst_a, lst_b, 'a');
	if (*lst_b && (*lst_b)->rank < c_mid)
		rotate(lst_b);
}

static void	chunk_loop(t_list **lst_a, t_list **lst_b, int c_size, int nb_c)
{
	int	mult;
	int	nb_push;
	int	chunk_mid;
	int	lst_size;

	mult = 1;
	nb_push = 0;
	lst_size = ft_lstsize(*lst_a);
	while (mult <= nb_c + 1)
	{
		chunk_mid = c_size * (mult - 1) + (c_size / 2) + 1;
		while (nb_push < c_size * mult && *lst_a)
		{
			push_elem(lst_a, lst_b, chunk_mid, c_size * mult);
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
	chunk_loop(lst_a, lst_b, chunk_size, nb_chunk);
	insertion_max(lst_a, lst_b);
}
