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
	else if (str[i] == 's')
		len += ft_putstr(fd, va_arg(list, char *));
	else if (str[i] == 'p')
		len += ft_pointer(fd, va_arg(list, unsigned long int));
	else if (str[i] == 'd' || str[i] == 'i')
		len += ft_putnbr(fd, va_arg(list, int));
	else if (str[i] == 'f')
		len += ft_putfloat(fd, va_arg(list, float));
	else if (str[i] == 'u')
		len += ft_putnbr(fd, va_arg(list, unsigned int));
	else if (str[i] == 'x')
		len += ft_hexa(fd, va_arg(list, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		len += ft_hexa(fd, va_arg(list, unsigned int), "0123456789ABCDEF");
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
