/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:13:38 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/22 11:13:41 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	results;

	results = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i ++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		results = (results * 10) + (str[i] - '0');
		i ++;
	}
	return (results * sign);
}

void	ft_convert_tobit(int pid, char c)
{
	int	i;

	i = 8;

	while (i--)
	{
		if ((1 & (c >> i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}
int main(int argc, char **argv)
{
    int i;
    int pid;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            ft_convert_tobit(pid, argv[2][i]);
            i++;
        }
    }
    if (argv[2][i] == '\0')
    {
        i = 0;
        while (i < 8)
        {
            kill(pid, SIGUSR2);
            usleep(500);
             i++;
        }
    }
    return(0);
}
