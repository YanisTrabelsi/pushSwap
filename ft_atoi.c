/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels <ytrabels@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 04:16:39 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/22 03:18:30 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	if (*nptr == '-' || *nptr == '+')
		s = 44 - *nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48) * s;
	return (res);
}
