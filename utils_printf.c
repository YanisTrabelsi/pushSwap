/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:31:55 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/08 16:31:57 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_putnbr(int fd, long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
		len ++;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(fd, nb / 10);
		nb = (nb % 10) + '0';
		write(fd, &nb, 1);
		len++;
	}
	else
	{
		nb += '0';
		write(fd, &nb, 1);
		len++;
	}
	return (len);
}

int	ft_putchar(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}
