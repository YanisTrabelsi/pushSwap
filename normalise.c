/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:04:53 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/27 19:04:56 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}
int	*complete_tab(t_list *lst, int *tab)
{
	int	i;

	i = 0;
	while (lst)
	{
		tab[i] = lst -> value;
		lst = lst -> next;
		i++;
	}
	return (tab);
}

void	sort_tab(int *tab, int max)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (max - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab [i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

void	normalise(t_list *lst)
{
	int	tab[ft_lstsize(lst)];
	int	i;

	tab = complete_tab(lst, tab);
	tab = sort_tab(tab, ft_lstsize(lst));
	while (i < ft_lstsize(lst))
	{

	}
}
