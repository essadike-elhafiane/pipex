/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:57:43 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/10 19:31:17 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex.h"

char	**get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH", 6))
			return (ft_split(env[i] +5, ':'));
	}
	return (NULL);
}

void	fork11(t_stk1 *y, int *fd, char **path, char **av)
{
	y->check_cmdf = 0;
	y->i = 0;
	y->cmd1 = ft_split(av[2], ' ');
	while (path[y->i])
	{
		y->path_cmd1 = ft_strjoin(path[y->i], y->cmd1[0]);
		if (!access(y->path_cmd1, X_OK))
		{
			y->check_cmdf = 1;
			break ;
		}
		free(y->path_cmd1);
		y->i++;
	}
	if (!y->check_cmdf)
		ft_puterror1("Error command path not fond !\n", av[4]);
	if (dup2(y->input, 0) < 0)
		ft_puterror("Error in dup2 !\n");
	if (dup2(fd[1], 1) < 0)
		ft_puterror("Error in dup2 !\n");
	ft_close_fd(y, fd);
	if (execve(y->path_cmd1, y->cmd1, NULL) < 0)
		ft_puterror("Error in execve !\n");
}

void	fork2(t_stk1 *y, int *fd, char **path, char **av)
{
	y->cmd1 = ft_split(av[3], ' ');
	y->check_cmdf = 0;
	y->i = 0;
	while (path[y->i])
	{
		y->path_cmd1 = ft_strjoin(path[y->i], y->cmd1[0]);
		if (!access(y->path_cmd1, X_OK))
		{
			y->check_cmdf = 1;
			break ;
		}
		free(y->path_cmd1);
		y->i++;
	}
	if (!y->check_cmdf)
		ft_puterror1("Error command path not fond !\n", av[4]);
	if (dup2(fd[0], 0) < 0)
		ft_puterror("Error in dup2 !\n");
	if (dup2(y->output, 1) < 0)
		ft_puterror("Error in dup2 !\n");
	ft_close_fd(y, fd);
	if (execve(y->path_cmd1, y->cmd1, NULL) < 0)
		ft_puterror("Error in execve !\n");
}

int	pipex(char **av, char **path)
{
	int		fd[2];
	pid_t	fork1;
	t_stk1	y;

	y.input = open(av[1], O_RDONLY, 0777);
	if (y.input < 0)
		ft_puterror("Error in file input\n");
	y.output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (y.output < 0)
		ft_puterror("Error in file output\n");
	if (pipe(fd) < 0)
		ft_puterror("Error in pipe !\n");
	exit_notpath(av, path);
	fork1 = fork();
	if (fork1 < 0)
		ft_puterror("Error in fork1 !\n");
	if (!fork1)
		fork11(&y, fd, path, av);
	fork1 = fork();
	if (fork1 < 0)
		ft_puterror("Error in fork2 !\n");
	if (!fork1)
		fork2(&y, fd, path, av);
	ft_close_fd(&y, fd);
	return (wait(NULL), wait(NULL), 0);
}

int	main(int ac, char **av, char **env)
{
	char	**path;

	if (ac == 5)
	{
		path = get_path(env);
		if (path == NULL)
			ft_puterror("Error in path !\n");
		if (ft_strchr(av[2], '/') || ft_strchr(av[3], '/'))
			cmd_with_path(av);
		pipex(av, path);
		ft_free(path);
	}
	else
		return (write(1, "Error arg !\n", 13), 1);
	return (0);
}
