/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_with_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:16:44 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/09 14:04:53 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_with_path1(char **av)
{
	char	*cmd1;
	int		i;
	int		j;

	i = 0;
	if (ft_strchr(av[3], '/'))
	{
		if (!access(av[3], X_OK))
		{
			i = ft_strlen(av[3]);
			j = i;
			while (av[3][i -1] != '/')
				i--;
			cmd1 = malloc(j - i +1);
			j = 0;
			while (av[3][i])
				cmd1[j++] = av[3][i++];
			cmd1[i] = '\0';
			av[3] = cmd1;
		}
	}
}

void	cmd_with_path(char **av)
{
	char	*cmd1;
	int		i;
	int		j;

	i = 0;
	if (ft_strchr(av[2], '/'))
	{
		if (!access(av[2], X_OK))
		{
			i = ft_strlen(av[2]);
			j = i;
			while (av[2][i -1] != '/')
				i--;
			cmd1 = malloc(j - i +1);
			j = 0;
			while (av[2][i])
				cmd1[j++] = av[2][i++];
			cmd1[i] = '\0';
			av[2] = cmd1;
		}
	}
	cmd_with_path1(av);
}
