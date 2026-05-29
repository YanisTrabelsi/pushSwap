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

static void	complete_tab(t_list *lst, int *tab)
{
	int	i;

	i = 0;
	while (lst)
	{
		tab[i] = lst -> value;
		lst = lst -> next;
		i++;
	}
}

static void	sort_tab(int *tab, int max)
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
			i = -1;
		}
		i++;
	}
}

void	normalise(t_list **lst)
{
	int		*tab;
	int		i;
	int		lstsize;
	t_list	*head;

	lstsize = ft_lstsize(*lst);
	tab = malloc(lstsize * sizeof(int));
	if (!tab)
		return ;
	i = 0;
	head = *lst;
	complete_tab(lst, tab);
	sort_tab(tab, lstsize);
	while (i < lstsize)
	{
		while (*lst -> value != tab[i])
			*lst = *lst -> next;
		*lst -> rank = i + 1;
		*lst = head;
		i++;
	}
	free(tab);
}
