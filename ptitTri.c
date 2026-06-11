/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptitTri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:22:51 by ytrabels          #+#    #+#             */
/*   Updated: 2026/06/12 00:44:10 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_list **lst_a)
{
	int	a;
	int	b;
	int	c;

	a = (*lst_a)->value;
	b = (*lst_a)->next->value;
	c = (*lst_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(lst_a, 0);
	else if (a > b && b > c)
	{
		swap_a(lst_a, 0);
		reverse_rotate_a(lst_a);
	}
	else if (a > b && b < c && a > c)
		reverse_rotate_a(lst_a);
	else if (a < b && b > c && a < c)
	{
		rotate_a(lst_a);
		swap_a(lst_a, 0);
	}
	else if (a < b && b > c && a > c)
		rotate_a(lst_a);
}

void	check_three(float disorder, t_list **lst_a, char c, char *str)
{
	int	nb_op;

	if (c == 1 || ft_strcmp(str, "--bench") == 1)
	{
		ft_printf(2, "Disorder: %f%%\n", disorder);
		ft_printf(2, "Strategy: Short / O(n)\n");
		sort_three(lst_a);
		nb_op = bench_rotate(0);
		nb_op += bench_pushswap(0);
		nb_op += bench_double(0);
		ft_printf(2, "Total_ops: %d\n", nb_op);
	}
	else
		sort_three(lst_a);
}

int	argparser(char **argv, int *i, t_list **lst_a)
{
	long	nb;

	while (argv[*i] && argv[*i][1] != '-')
	{
		nb = ft_atoi(argv[*i]);
		if (nb < -2147483648 || nb > 2147483647 || is_duplicate(nb, *lst_a)
			|| check_args(argv[*i]) == 0)
			return (ft_printf(2, "ERROR\n"));
		ft_lstadd_back(lst_a, ft_lstnew(nb, 0));
		++*i;
	}
	return (0);
}
