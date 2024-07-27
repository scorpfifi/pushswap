/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sever.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:13:26 by vmpianim          #+#    #+#             */
/*   Updated: 2024/07/22 11:13:29 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"

char	*ft_strjoin(char const *s1, char const s2)
{
	int		i;
	int		len1;
	char	*str;

    if(!s1)
    {
        str = malloc(sizeof(char) * 2);
        str[0] = s2 ;
        str[1] = '\0';
        return(str);
    }
	len1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len1 + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	str[len1] = s2;
	len1++;
	str[len1] = '\0';
	return (str);
}

void	ft_convert_tobit(int sig)
{
	static int	bit = 0;
	static char	c = 0;
	static char	*message;

	if (sig == SIGUSR1)
		c |= (1 << ( 7 - bit));
    else
        c |= 0;
    bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s", message);
			ft_printf("\n");
			free(message);
			message = NULL;
		}
        else
		    message = ft_strjoin (message, c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
    ft_strjoin("bonjour", 'c');
	while (argc == 1)
	{
		signal(SIGUSR2, ft_convert_tobit);
		signal(SIGUSR1, ft_convert_tobit);
		pause();
	}
	return (0);
}