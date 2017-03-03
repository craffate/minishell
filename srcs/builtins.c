/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:04:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/03 14:47:48 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		exec_builtin(const char **argv, char ***envp)
{
	if (!ft_strcmp(argv[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strcmp(argv[0], "cd"))
		builtin_cd(argv, *envp);
	else if (!ft_strcmp(argv[0], "echo"))
		builtin_echo(argv);
	else if (!ft_strcmp(argv[0], "env"))
		builtin_env((const char **)*envp);
	else if (!ft_strcmp(argv[0], "setenv"))
		builtin_setenv(argv, envp);
	else if (!ft_strcmp(argv[0], "unsetenv"))
		builtin_unsetenv(argv, envp);
	else
		return ;
}

void		builtin_echo(const char **argv)
{
	unsigned int	i;

	while (*++argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if ((*argv)[i] == '"')
				i++;
			write(1, &(*argv)[i], 1);
			i++;
		}
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void		builtin_env(const char **envp)
{
	unsigned int	i;

	i = 0;
	while (envp[i])
	{
		write(1, envp[i], ft_strlen(envp[i]));
		write(1, "\n", 1);
		i++;
	}
}

void		builtin_cd(const char **argv, char **envp)
{
	int		i;
	int		j;
	char	*ptr;

	i = find_env((const char **)envp, "PWD=");
	j = find_env((const char **)envp, "OLDPWD=");
	ptr = envp[i] + 4;
	free(envp[j]);
	envp[j] = ft_strjoin("OLDPWD=", ptr);
	if (*argv[1] != '/')
		ptr = join_path(ptr, argv[1]);
	else
		ptr = ft_strdup(argv[1]);
	if (access(ptr, F_OK))
	{
		error_handler(9);
		return ;
	}
	if (access(ptr, R_OK))
	{
		error_handler(6);
		return ;
	}
	chdir(ptr);
	free(ptr);
	ptr = getcwd(NULL, MSH_BUFSIZE);
	envp[i] = ft_strjoin("PWD=", ptr);
	free(ptr);
	ptr = NULL;
}
