/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrabels </var/spool/mail/ytrabels>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:15:22 by ytrabels          #+#    #+#             */
/*   Updated: 2026/05/27 19:04:19 by ytrabels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;
t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelfront(t_list **lst);
float				ft_disorder(t_list *lst);
int					is_duplicate(int nb, t_list *lst);
void				swap(t_list	**lst);
void				push(t_list	**lst_from, t_list	**lst_to, char c);
void				rotate(t_list	**lst);
void				reverse_rotate(t_list	**lst);
void				insertion(t_list **lsta, t_list **lstb);
long				ft_atoi(const char *nptr);
int					ft_lstsize(t_list *lst);
void				normalise(t_list *lst);
#endif
