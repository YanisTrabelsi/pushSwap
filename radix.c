/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:43:14 by lherpet           #+#    #+#             */
/*   Updated: 2026/06/10 15:43:16 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

static void	bit_check(t_list **lst_a, t_list **lst_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*lst_a);
	while (size_a > 0)
	{
		if ((*lst_a)->rank & 1)
			rotate_a(lst_a);
		else
			push(lst_a, lst_b, 'b');
		--size_a;
	}
	size_b = ft_lstsize(*lst_b);
	while (size_b > 0)
	{
		push(lst_b, lst_a, 'a');
		--size_b;
	}
}

static void	right_shift(t_list *lst)
{
	while (lst)
	{
		lst->rank = lst->rank >> 1;
		lst = lst->next;
	}
}

static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	radix(t_list **lst_a, t_list **lst_b)
{
	int	i;

	i = max_bits(ft_lstsize(*lst_a));
	normalise(*lst_a);
	while (i > 0)
	{
		bit_check(lst_a, lst_b);
		right_shift(*lst_a);
		--i;
	}
}
