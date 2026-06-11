/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 02:49:44 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/22 02:51:03 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
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

int	is_duplicate(int nb, t_list *lst)
{
	while (lst)
	{
		if (nb == lst -> value)
			return (1);
		lst = lst -> next;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			++i;
		else
			return (0);
	}
	return (1);
}

float	ft_disorder(t_list *lst)
{
	float	disorder;
	int		nb_paires;
	int		base;
	t_list	*compare;

	if (!lst)
		return (0.0f);
	disorder = 0.0f;
	nb_paires = 0;
	while (lst->next != NULL)
	{
		base = lst->value;
		compare = lst->next;
		while (compare)
		{
			if (base > compare->value)
				disorder += 1.0f;
			compare = compare->next;
			nb_paires++;
		}
		lst = lst->next;
	}
	return ((disorder / nb_paires) * 100);
}
