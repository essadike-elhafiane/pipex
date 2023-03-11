/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:59:54 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/09 14:05:49 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct t_stk
{
	int		output;
	int		input;
	int		check_cmdf;
	int		i;
	int		j;
	char	**cmd1;
	char	*path_cmd1;
}	t_stk1;

void	ft_free(char **s);
void	ft_puterror(char *s);
void	ft_puterror1(char *s, char *namefd);
void	ft_close_fd(t_stk1 *y, int *fd);
void	exit_notpath(char **av, char **path);
void	cmd_with_path(char **av);
#endif