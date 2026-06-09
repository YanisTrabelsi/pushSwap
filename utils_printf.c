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
		len += ft_putnbr(nb / 10);
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

int	ft_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_hexa_p(int fd, unsigned long int nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_hexa(nb / 16, base);
		nb = nb % 16;
		write(fd, &base[nb], 1);
		len++;
	}
	else
	{
		write(fd, &base[nb], 1);
		len++;
	}
	return (len);
}

int	ft_pointer(int fd, unsigned long int p)
{
	int	length;

	if (!p)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	length = 0;
	write (fd, "0x", 2);
	length += 2;
	length += ft_hexa_p(fd, p, "0123456789abcdef");
	return (length);
}
