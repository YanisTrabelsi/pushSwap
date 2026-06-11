/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:31:04 by lherpet           #+#    #+#             */
/*   Updated: 2026/06/04 12:32:26 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bench_rotate(int i)
{
	static int	ra;
	static int	rb;
	static int	rra;
	static int	rrb;

	if (i == 1)
		ra++;
	if (i == 2)
		rb++;
	if (i == 3)
		rra++;
	if (i == 4)
		rrb++;
	if (i == 0)
		ft_printf(2, "ra:%d rb:%d rra:%d rrb:%d\n", ra, rb, rra, rrb);
	return (ra + rb + rra + rrb);
}

int	bench_pushswap(int i)
{
	static int	sa;
	static int	sb;
	static int	pa;
	static int	pb;

	if (i == 1)
		sa++;
	if (i == 2)
		sb++;
	if (i == 3)
		pa++;
	if (i == 4)
		pb++;
	if (i == 0)
		ft_printf(2, "sa:%d sb:%d pa:%d pb:%d\n", sa, sb, pa, pb);
	return (sa + sb + pa + pb);
}

int	bench_double(int i)
{
	static int	rr;
	static int	rrr;
	static int	ss;

	if (i == 1)
		rr++;
	if (i == 2)
		rrr++;
	if (i == 3)
		ss++;
	if (i == 0)
		ft_printf(2, "rr:%d rrr:%d ss:%d\n", rr, rrr, ss);
	return (rr + rrr + ss);
}

static void	display_adaptative(float disorder, t_list **lst_a, t_list **lst_b)
{
	ft_printf(2, "Strategy: Adapative / ");
	if (ft_lstsize(*lst_a) == 5)
	{
		ft_printf(2, "O(n√n)\n");
		return (chunk_base(lst_a, lst_b));
	}
	if (disorder < 0.2f)
	{
		ft_printf(2, "O(nn2)\n");
		return (insertion(lst_a, lst_b));
	}
	if (disorder < 0.5f)
	{
		ft_printf(2, "O(n√n)\n");
		return (chunk_base(lst_a, lst_b));
	}
	else
	{
		ft_printf(2, "O(nlogn)\n");
		return (radix(lst_a, lst_b));
	}
}

void	display_bench(float disorder, char *arg, t_list **lst_a, t_list **lst_b)
{
	int	nb_op;

	ft_printf(2, "Disorder: %f%%\n", disorder);
	if (ft_strcmp(arg, "--simple") == 1)
	{
		ft_printf(2, "Strategy: Simple / O(nn2)\n");
		insertion(lst_a, lst_b);
	}
	else if (ft_strcmp(arg, "--medium") == 1)
	{
		ft_printf(2, "Strategy: Medium / O(n√n)\n");
		chunk_base(lst_a, lst_b);
	}
	else if (ft_strcmp(arg, "--complex") == 1)
	{
		ft_printf(2, "Strategy: Complex / O(nlogn)\n");
		radix(lst_a, lst_b);
	}
	else
		display_adaptative(disorder, lst_a, lst_b);
	nb_op = bench_rotate(0);
	nb_op += bench_pushswap(0);
	nb_op += bench_double(0);
	ft_printf(2, "Total_ops: %d\n", nb_op);
}
