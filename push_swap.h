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

/* utils_lst.c */
t_list				*ft_lstnew(int value, int rank);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelfront(t_list **lst);
int					ft_lstsize(t_list *lst);

/* parsing.c */
long				ft_atoi(const char *nptr);
int					is_duplicate(int nb, t_list *lst);
float				ft_disorder(t_list *lst);

/* normalise.c */
void				normalise(t_list *lst);

/* operations.c */
void				swap_a(t_list **lst, int c);
void				swap_b(t_list **lst, int c);
void				swap_swap(t_list **lst_a, t_list **lst_b);
void				push(t_list **lst_from, t_list **lst_to, char c);
void				reverse_rotate_rotate(t_list **lst_a, t_list **lst_b);

/* operations2.c */
void				rotate_a(t_list **lst);
void				rotate_b(t_list **lst);
void				rotate_rotate(t_list **lst_a, t_list **lst_b);
void				reverse_rotate_a(t_list **lst);
void				reverse_rotate_b(t_list **lst);

/* bench.c */
void				bench_rotate(int i);
void				bench_pushswap(int i);
void				bench_double(int i);

/* insertion.c */
void				insertion(t_list **lsta, t_list **lstb);

/* insertion_max.c */
void				insertion_max(t_list **lsta, t_list **lstb, t_bench *count);

/* chunk_base.c */
void				chunk_base(t_list **lst_a, t_list **lst_b);

/* ft_printf.c */
int					ft_printf(int fd, const char *str, ...);

/* utils_pritf */
int					ft_putnbr(int fd, long int nb);
int					ft_putstr(int fd, char *s);
int					ft_putchar(int fd, int c);
int					ft_hexa_p(int fd, unsigned long int nb, char *base);
int					ft_pointer(int fd, unsigned long int p);

#endif
