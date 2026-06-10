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
		ft_printf(2, "ra:%d\nrb:%d\nrra:%d\nrrb:%d\n", ra, rb, rra, rrb);
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
		ft_printf(2, "sa:%d\nsb:%d\npa:%d\npb:%d\n", sa, sb, pa, pb);
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
		ft_printf(2, "rr:%d\nrrr:%d\nss:%d\n", rr, rrr, ss);
	return (rr + rrr + ss);
}
