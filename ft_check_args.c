/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:03:48 by vmpianim          #+#    #+#             */
/*   Updated: 2024/05/24 09:44:09 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_generate_char(int argc, char **argv)
{
	char	*str;
	int		i;
	int		h;
	int		j;

	i = 0;
	h = 0;
	str = malloc(sizeof(char) * (argc * 2) + 1);
	if (str == NULL)
		return (NULL);
	while (i < (argc - 1))
	{
		i++;
		j = 0;
		while (argv[i][j])
		{
			str[h] = argv[i][j];
			j++;
			h++;
		}
		str[h] = ' ';
		h++;
	}
	str[h] = '\0';
	return (str);
}

int	ft_check_error(int argc, char **argv)
{
	char	*str;

	if (argc == 2 && ft_check_string(argv[1]) && ft_check_digit(argv[1])
		&& ft_check_double_sign(argv[1]))
		return (1);
	if (argc > 2 && !ft_check_string(argv[1]))
	{
		str = ft_generate_char(argc, argv);
		if (ft_check_digit(str) && ft_check_double_sign(str))
			return (1);
		return (0);
	}
	return (0);
}

char	**ft_splited(int argc, char **argv)
{
	char	**splited;
	char	*str;

	if (argc == 2)
		splited = ft_split(argv[1], ' ');
	else
	{
		str = ft_generate_char(argc, argv);
		splited = ft_split(str, ' ');
	}
	return (splited);
}
