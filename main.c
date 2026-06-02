/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:23:49 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/22 03:44:40 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_lstclear(t_list **lst)
{
	t_list	*first;
	t_list	*next;

	first = *lst;
	while (first)
	{
		next = first -> next;
		free(first);
		first = next;
	}
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	long	nb;
	t_list	*lst_a;
	t_list	*lst_b;

	(void)argc;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, lst_a))
			return (1);
		ft_lstadd_back(&lst_a, ft_lstnew(nb, 0));
		++i;
	}
	chunk_base(&lst_a, &lst_b);
	printf("==LSTA==\n");
	while (lst_a)
	{
		printf("|| %d ||\n", lst_a->value);
		lst_a = lst_a->next;
	}
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
