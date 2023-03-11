/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:13:57 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/06 22:10:26 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_notpath(char **av, char **path)
{
	t_stk1	y;

	y.j = 1;
	while (++y.j < 4)
	{
		y.check_cmdf = 0;
		y.i = 0;
		y.cmd1 = ft_split(av[y.j], ' ');
		while (path[y.i])
		{
			y.path_cmd1 = ft_strjoin(path[y.i], y.cmd1[0]);
			if (!access(y.path_cmd1, X_OK))
			{
				y.check_cmdf = 1;
				break ;
			}
			free(y.path_cmd1);
			y.i++;
		}
		ft_free(y.cmd1);
		if (!y.check_cmdf)
			ft_puterror1("Error command path not fond !\n", av[4]);
		else
			free(y.path_cmd1);
	}
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_close_fd(t_stk1 *y, int *fd)
{
	close(y->input);
	close(y->output);
	close(fd[1]);
	close(fd[0]);
}

void	ft_puterror(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);
}

void	ft_puterror1(char *s, char *namefd)
{
	ft_putstr_fd(s, 1);
	unlink(namefd);
	exit(1);
}
