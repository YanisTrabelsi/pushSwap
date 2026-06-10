/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lherpet <lherpet@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:03:09 by lherpet           #+#    #+#             */
/*   Updated: 2026/05/08 15:03:39 by lherpet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdarg.h>

static int	ft_putfloat(int fd, int nb)
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
		if (nb >= 100 && nb <= 999)
			write(fd, ".", 1);
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

static int	ft_float_to_int(int fd, float f)
{
	int	nb;
	int	len;

	nb = (int)(f * 100);
	len = ft_putfloat(fd, nb);
	return (len + 1);
}

static int	special_char(int fd, const char *str, int i, va_list list)
{
	int	len;

	len = 0;
	if (str[i] == '%')
	{
		write(1, "%", 1);
		len++;
	}
	if (str[i] == 'c')
		len += ft_putchar(fd, va_arg(list, int));
	else if (str[i] == 'd' || str[i] == 'i')
		len += ft_putnbr(fd, va_arg(list, int));
	else if (str[i] == 'f')
		len += ft_float_to_int(fd, va_arg(list, double));
	return (len);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	if (!str)
		return (-1);
	va_start(list, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += special_char(fd, str, i, list);
		}
		else
		{
			write(fd, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(list);
	return (len);
}
