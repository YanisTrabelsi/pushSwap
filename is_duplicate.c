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

#include "libft.h"

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
