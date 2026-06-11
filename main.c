/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:23:49 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/22 03:44:40 by ytrabels         ###   ########.fr       */
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

void	flagparser(char *arg, char *next_arg, t_list **lst_a, t_list **lst_b)
{
	float	disorder;

	disorder = ft_disorder(*lst_a);
	if (ft_strcmp(arg, "--bench") == 1)
		return (display_bench(disorder, next_arg, lst_a, lst_b));
	if (ft_strcmp(next_arg, "--bench") == 1)
		return (display_bench(disorder, arg, lst_a, lst_b));
	if (ft_strcmp(arg, "--simple") == 1)
		return (insertion(lst_a, lst_b));
	if (ft_strcmp(arg, "--medium") == 1)
		return (chunk_base(lst_a, lst_b));
	if (ft_strcmp(arg, "--complex") == 1)
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

int	check_flag(char *str)
{
	if (ft_strcmp(str, "--bench") == 1)
		return (0);
	if (ft_strcmp(str, "--simple") == 1)
		return (0);
	if (ft_strcmp(str, "--medium") == 1)
		return (0);
	if (ft_strcmp(str, "--complex") == 1)
		return (0);
	return (ft_printf(2, "ERROR\n"));
}

void	lstclear(t_list **lst)
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
	lst = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	char	bench;
	t_list	*lst_a;
	t_list	*lst_b;

	(void)argc;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	if (ft_strcmp(argv[i], "--bench") == 1)
	{
		bench = 1;
		++i;
	}
	if (argparser(argv, &i, &lst_a) != 0)
		return (lstclear(&lst_a), 1);
	if (argv[i] && check_flag(argv[i]) != 0)
		return (lstclear(&lst_a), 1);
	if (ft_disorder(lst_a) == 0.00f)
		return (lstclear(&lst_a), 0);
	if (bench == 0)
		flagparser(argv[i], argv[i + 1], &lst_a, &lst_b);
	else
		display_bench(ft_disorder(lst_a), argv[i], &lst_a, &lst_b);
	return (lstclear(&lst_a), lstclear(&lst_b), 0);
}
