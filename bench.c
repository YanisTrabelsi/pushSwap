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

t_bench	struct_define(void)
{
	t_bench	count;

	count = malloc(sizeof(t_bench));
	if (!count)
		return ;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->pa = 0;
	count->pb = 0;
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	return (count);
}
