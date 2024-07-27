/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:24:10 by vmpianim          #+#    #+#             */
/*   Updated: 2024/04/08 11:07:35 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

char	*ft_strchr(const char *s, int c);
int		ft_check_type(va_list args, char specifieur);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putbasehexa_low(uintptr_t nb);
int		ft_putbasehexa_upper(unsigned int nb);
int		ft_print_ptr(va_list args);
size_t	ft_strlen(const char *str);

#endif
