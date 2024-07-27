/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:42:45 by vmpianim          #+#    #+#             */
/*   Updated: 2024/04/08 11:00:21 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbasehexa_low(uintptr_t nb)
{
	int		count;
	char	*base;

	nb = (uintptr_t)nb;
	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_putbasehexa_low(nb / 16);
		count += ft_putbasehexa_low(nb % 16);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}

int	ft_putbasehexa_upper(unsigned int nb)
{
	char	*base;
	int		count;

	nb = (unsigned int)nb;
	count = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putbasehexa_upper(nb / 16);
		count += ft_putbasehexa_upper(nb % 16);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
