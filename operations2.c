/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:33:44 by lherpet           #+#    #+#             */
/*   Updated: 2026/06/08 20:33:46 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list	**lst)
{
	ft_lstadd_back(lst, ft_lstnew((*lst)->value, (*lst)->rank));
	ft_lstdelfront(lst);
	printf("ra\n");
	bench_rotate(1);
}

void	rotate_b(t_list	**lst)
{
	ft_lstadd_back(lst, ft_lstnew((*lst)->value, (*lst)->rank));
	ft_lstdelfront(lst);
	printf("rb\n");
	bench_rotate(2);
}

void	rotate_rotate(t_list **lst_a, t_list **lst_b)
{
	ft_lstadd_back(lst_a, ft_lstnew((*lst_a)->value, (*lst_a)->rank));
	ft_lstdelfront(lst_a);
	ft_lstadd_back(lst_b, ft_lstnew((*lst_b)->value, (*lst_b)->rank));
	ft_lstdelfront(lst_b);
	printf("rr\n");
	bench_double(1);
}

void	reverse_rotate_b(t_list	**lst)
{
	t_list	*temp;

	ft_lstadd_front(lst, ft_lstnew(ft_lstlast(*lst)->value,
			ft_lstlast(*lst)->rank));
	temp = ft_lstlast(*lst);
	if (temp -> prev)
		temp -> prev -> next = NULL;
	free (temp);
	printf("rrb\n");
	bench_rotate(4);
}

void	reverse_rotate_a(t_list	**lst)
{
	t_list	*temp;

	ft_lstadd_front(lst, ft_lstnew(ft_lstlast(*lst)->value,
			ft_lstlast(*lst)->rank));
	temp = ft_lstlast(*lst);
	if (temp -> prev)
		temp -> prev -> next = NULL;
	free (temp);
	printf("rra\n");
	bench_rotate(3);
}
