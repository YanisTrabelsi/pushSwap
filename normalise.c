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

void	complete_tab(t_list *lst, int *tab)
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
			i = -1;
		}
		i++;
	}
}

void	normalise(t_list *lst)
{
	int		*tab;
	int		i;
	t_list	*head;

	tab = malloc(ft_lstsize(lst) * sizeof(int));
	if (!tab)
		return ;
	i = 0;
	head = lst;
	complete_tab(lst, tab);
	sort_tab(tab, ft_lstsize(lst));
	while (i < ft_lstsize(lst))
	{
		while (lst -> value != tab[i])
			lst = lst -> next;
		lst -> rank = i + 1;
		lst = head;
		i++;
	}
	free(tab);
}

/*int	main(void)
{
	int		tab[10];
	int		i;
	long	nb;
	t_list	*lst_a;
	//t_list	*lst_b;

	tab[0] = -7;
	tab[1] = 10;
	tab[2] = 3;
	tab[3] = 16;
	tab[4] = 54;
	tab[5] = 900;
	tab[6] = 2;
	tab[7] = 44;
	tab[8] = -13;
	tab[9] = 1;
	i = 0;
	while (i < 10)
	{
		nb = tab[i];
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, lst_a))
			return (printf("ERROR\n"), 1);
		ft_lstadd_back(&lst_a, ft_lstnew(nb));
		++i;
	}
	//met ta fonction de tri ici avec lst_a et lst_b en parametre
	normalise(lst_a);
	while (lst_a)
	{
		printf("|| %d || || %d ||\n", lst_a -> value, lst_a -> rank);
		lst_a = lst_a->next;
	}
}*/
