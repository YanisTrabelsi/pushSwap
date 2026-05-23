/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:23:49 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/23 03:38:22 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int		i;
	long	nb;
	t_list	*lst_a;
	t_list	*head_a;

	i = 1;
	lst_a = NULL;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, lst_a))
			return (1);
		ft_lstadd_back(&lst_a, ft_lstnew(nb));
		++i;
	}
	head_a = lst_a;
	while (lst_a)
	{
		printf("| %d |", lst_a->value);
		lst_a = lst_a->next;
	}
	printf("\n");
	lst_a = head_a;
	//fonction de tri
	bubble(lst_a);
	/*
	while (lst_a)
	{
		printf("|| %d ||\n", lst_a->value);
		lst_a = lst_a->next;
	}
	*/
}
