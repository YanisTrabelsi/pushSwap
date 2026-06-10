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

static void	argparser(char *arg, char *next_arg, t_list **lst_a, t_list **lst_b)
{
	float	disorder;

	disorder = ft_disorder(*lst_a);
	if (ft_strcmp(arg, "--bench") == 1)
		return (display_bench(disorder, next_arg, lst_a, lst_b));
	if (ft_strcmp(arg, "--simple") == 1)
		return (insertion(lst_a, lst_b));
	if (ft_strcmp(arg, "--medium") == 1)
		return (chunk_base(lst_a, lst_b));
	if (ft_strcmp(arg, "--complex") == 1)
		return (radix(lst_a, lst_b));
	else
	{
		if (disorder < 0.2f)
			return (insertion(lst_a, lst_b));
		if (disorder < 0.5f)
			return (chunk_base(lst_a, lst_b));
		else
			return (radix(lst_a, lst_b));
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb_op;
	long	nb;
	t_list	*lst_a;
	t_list	*lst_b;

	(void)argc;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	while (argv[i] && argv[i][1] != '-')
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, lst_a))
			return (1);
		ft_lstadd_back(&lst_a, ft_lstnew(nb, 0));
		++i;
	}
	argparser(argv[i], argv[i + 1], &lst_a, &lst_b);
}
