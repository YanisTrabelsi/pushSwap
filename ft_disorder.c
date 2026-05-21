/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:20:51 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/21 23:20:52 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_disorder(t_list *lst)
{
	float	disorder;
	int		nb_paires;
	int		base;
	t_list	*compare;

	if (!lst)
		return (NULL);
	disorder = 0.0f;
	nb_paires = 0;
	base = lst -> value;
	while (lst -> next != NULL)
	{
		compare = lst -> next;
		while (compare)
		{
			if (base > compare -> value)
				disorder += 1.0f;
			compare = compare -> next;
			nb_paires++;
		}
		lst = lst -> next;
	}
	return (disorder / nb_paires);
}
