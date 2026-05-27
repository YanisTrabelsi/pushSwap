/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:20:51 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/22 02:51:18 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

float	ft_disorder(t_list *lst)
{
	float	disorder;
	int		nb_paires;
	int		base;
	t_list	*compare;

	if (!lst)
		return (0.0f);
	disorder = 0.0f;
	nb_paires = 0;
	while (lst->next != NULL)
	{
		base = lst->value;
		compare = lst->next;
		while (compare)
		{
			if (base > compare->value)
				disorder += 1.0f;
			compare = compare->next;
			nb_paires++;
		}
		lst = lst->next;
	}
	return (disorder / nb_paires);
}

int	is_duplicate(int nb, t_list *lst)
{
	while (lst)
	{
		if (nb == lst -> value)
			return (1);
		lst = lst -> next;
	}
	return (0);
}
