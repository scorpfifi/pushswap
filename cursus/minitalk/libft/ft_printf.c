/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:10:33 by vmpianim          #+#    #+#             */
/*   Updated: 2024/04/08 11:06:47 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_print_ptr(va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putbasehexa_low((uintptr_t)ptr);
	}
	return (count);
}

int	ft_check_type(va_list args, char specifieur)
{
	int		count;

	count = 0;
	if (specifieur == 'c')
		count += (ft_putchar(va_arg(args, int)));
	else if (specifieur == 's')
		count += (ft_putstr(va_arg(args, char *)));
	else if (specifieur == 'd' || specifieur == 'i')
		count += (ft_putnbr(va_arg(args, int)));
	else if (specifieur == 'u')
		count += (ft_putunbr(va_arg(args, unsigned int)));
	else if (specifieur == 'x')
		count += (ft_putbasehexa_low(va_arg(args, unsigned int)));
	else if (specifieur == 'X')
		count += (ft_putbasehexa_upper(va_arg(args, unsigned int)));
	else if (specifieur == 'p')
		count += ft_print_ptr(args);
	else if (specifieur == '%')
		count += ft_putstr("%");
	else
		count = 0;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
			count += ft_check_type(args, str[++i]);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
