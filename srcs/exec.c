/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:06:24 by craffate          #+#    #+#             */
/*   Updated: 2017/03/03 09:55:21 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*find_binary(const char *bin, const char **path)
{
	unsigned int	i;
	char			*buf;
	char			*ret;

	i = 0;
	buf = NULL;
	while (path[i])
	{
		buf = join_path(path[i], bin);
		if (!access(buf, X_OK))
			break ;
		i++;
		free(buf);
	}
	ret = ft_strdup(buf);
	buf ? free(buf) : 0;
	if (!ret)
	{
		error_handler(5);
		free(ret);
	}
	return (ret);
}

int			exec(char **argv, char ***envp)
{
	char	**path;
	pid_t	child;
	int		status;
	char	*bin_path;

	if (!argv[0])
		return (-1);
	path = split_path((const char **)*envp);
	bin_path = find_binary(argv[0], (const char **)path);
	free(path);
	if (isbuiltin(argv[0]))
	{
		exec_builtin((const char **)argv, envp);
		return (0);
	}
	child = fork();
	if (child == 0)
	{
		if (*argv[0] == '/' || *argv[0] == '.')
			execve(argv[0], argv, *envp);
		else
			execve(bin_path, argv, *envp);
		error_handler(4);
		exit(EXIT_FAILURE);
	}
	else if (child > 0)
		wait(&status);
	else
		error_handler(3);
	free_env(argv);
	return (0);
}
