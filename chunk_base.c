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

void	chunk_base(t_list **lst_a, t_list **lst_b)
{
	int	lst_size;
	int	nb_chunk;
	int	index;
	int	mult;
	int	rank_value;
	t_list	*head;

	normalise(lst_a);
	i = 0;
	mult = 1;
	lst_size = ft_lstsize(*lst_a);
	if (lst_size <= 100)
		nb_chunk = 5;
	else
		nb_chunk = 11;
	head = (*lst_a);
	while(*lst_a)
	{
		while ((*lst_a) -> rank > (lst_size/nb_chunk) * mult)
		{
			(*lst_a) = (*lst_a) -> next;
			i++;
		}
		if (i > ft_lstsize(*lst_a)/2)
		{
			rank_value = (*lst_a) -> rank;
			while (ft_lstlast(*lst_a)-> rank != rank_value)
				reverse_rotate(lst_a);
			reverse_rotate(lst_a);
			push(lst_a, lst_b, a);
		}
	}
}
