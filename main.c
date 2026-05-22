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

int	main(int argc, char **argv)
{
	(void)argc;
	int		i;
	long	nb;
	t_list	*lst_a;
	t_list	*lst_b;

	i = 1;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, lst_a))
			return (1);
		ft_lstadd_back(&lst, ft_lstnew(nb));
		++i;
	}
	//met ta fonction de tri ici avec lst_a et lst_b en parametre
	while (lst_a)
	{
		printf("|| %d ||\n", lst_a->value);
		lst_a = lst_a->next;
	}
}
