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

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

float	ft_disorder(t_list *lst)
{
	float	disorder;
	int		nb_paires;
	int		base;
	t_list	*compare;

	if (!lst)
		return (NULL);
	disorder = 0;
	nb_paires = 1;
	base = lst -> value;
	while (lst -> next != NULL)
	{
		compare = lst -> next;
		while(compare)
		{
			if (base > compare -> value)
				disorder += 1.0;
			compare = compare -> next;
			nb_paires++;
		}
		lst = lst -> next;
	}
	return (disorder / nb_paires);
}
