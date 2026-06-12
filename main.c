/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:23:49 by ytrabels          #+#    #+#             */
/*   Updated: 2026/06/12 07:28:05 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_args(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		++i;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

static void	flagparser(char *arg1, char *arg2, t_list **lst_a, t_list **lst_b)
{
	float	disorder;

	disorder = ft_disorder(*lst_a);
	if (ft_strcmp(arg1, "--bench") == 1)
		return (display_bench(disorder, arg2, lst_a, lst_b));
	if (ft_strcmp(arg2, "--bench") == 1)
		return (display_bench(disorder, arg1, lst_a, lst_b));
	if (ft_strcmp(arg1, "--simple") == 1)
		return (insertion(lst_a, lst_b));
	if (ft_strcmp(arg1, "--medium") == 1)
		return (chunk_base(lst_a, lst_b));
	if (ft_strcmp(arg1, "--complex") == 1)
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

static void	check_flag(char **argv, int *i)
{
	int	nb;

	nb = 0;
	while(nb < 2)
	{
		if (ft_strcmp(argv[*i], "--bench") == 1)
			(*i)++;
		if (ft_strcmp(argv[*i], "--simple") == 1)
			(*i)++;
		if (ft_strcmp(argv[*i], "--medium") == 1)
			(*i)++;
		if (ft_strcmp(argv[*i], "--complex") == 1)
			(*i)++;
		nb++;
	}
}

static void	lstclear(t_list **lst)
{ 
	t_list	*temp;

	if (!*lst)
		return ;
	temp = *lst;
	*lst = temp->next;
	while (*lst)
	{
		free(temp);
		temp = *lst;
		*lst = temp->next;
	}
	free(temp);
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst_a;
	t_list	*lst_b;

	(void)argc;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	check_flag(argv, &i);
	if (argparser(argv, &i, &lst_a) != 0)
		return (lstclear(&lst_a), 1);
	if (ft_disorder(lst_a) == 0.00f)
		return (lstclear(&lst_a), 0);
	flagparser(argv[1], argv[2], &lst_a, &lst_b);
	return (lstclear(&lst_a), lstclear(&lst_b), 0);
}
