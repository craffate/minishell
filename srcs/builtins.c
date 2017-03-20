/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:04:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/20 16:27:56 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void			exec_builtin(const char **argv, char ***envp)
{
	if (!ft_strcmp(argv[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strcmp(argv[0], "cd") && !argv[1])
		builtin_cd_nopath(*envp);
	else if (!ft_strcmp(argv[0], "cd") && !ft_strcmp(argv[1], "-"))
		builtin_cd_prev(*envp);
	else if (!ft_strcmp(argv[0], "cd") && argv[1])
		builtin_cd(argv, *envp);
	else if (!ft_strcmp(argv[0], "echo"))
		builtin_echo(argv);
	else if (!ft_strcmp(argv[0], "env"))
		builtin_env((const char **)*envp);
	else if (!ft_strcmp(argv[0], "setenv"))
		builtin_setenv(argv, envp);
	else if (!ft_strcmp(argv[0], "unsetenv"))
		builtin_unsetenv(argv, envp);
}

void			builtin_cd_prev(char **envp)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;
	char			*ptr2;

	i = find_env((const char **)envp, "PWD=");
	j = find_env((const char **)envp, "OLDPWD=");
	ptr = ft_strdup(envp[i] + 4);
	ptr2 = ft_strdup(envp[j] + 7);
	free(envp[j]);
	free(envp[i]);
	envp[j] = ft_strjoin("OLDPWD=", ptr);
	envp[i] = ft_strjoin("PWD=", ptr2);
	chdir(ptr2);
	free(ptr);
	ptr = NULL;
	free(ptr2);
	ptr2 = NULL;
}

void			builtin_cd_nopath(char **envp)
{
	int		i;
	int		j;
	char	*ptr;

	if (find_env((const char **)envp, "HOME=") == -1)
	{
		error_handler(10);
		return ;
	}
	i = find_env((const char **)envp, "PWD=");
	j = find_env((const char **)envp, "OLDPWD=");
	ptr = envp[i] + 4;
	free(envp[j]);
	envp[j] = ft_strjoin("OLDPWD=", ptr);
	ptr = envp[find_env((const char **)envp, "HOME=")] + 5;
	free(envp[i]);
	envp[i] = ft_strjoin("PWD=", ptr);
	chdir(ptr);
}

static int		builtin_cd2(const char **argv, char **ptr)
{
	if (*argv[1] != '/')
		*ptr = join_path(*ptr, argv[1]);
	else
		*ptr = ft_strdup(argv[1]);
	if (access(*ptr, F_OK))
	{
		error_handler(9);
		return (-1);
	}
	if (access(*ptr, R_OK))
	{
		error_handler(6);
		return (-1);
	}
	return (0);
}

void			builtin_cd(const char **argv, char **envp)
{
	int		i;
	int		j;
	char	*ptr;
	char	*ptr2;

	if (!argv[1])
	{
		builtin_cd_nopath(envp);
		return ;
	}
	i = find_env((const char **)envp, "PWD=");
	j = find_env((const char **)envp, "OLDPWD=");
	ptr = envp[i] + 4;
	ptr2 = ptr;
	if (builtin_cd2(argv, &ptr))
	{
		free(ptr);
		return ;
	}
	free(envp[j]);
	envp[j] = ft_strjoin("OLDPWD=", ptr2);
	builtin_cd_chdir(&ptr);
	free(envp[i]);
	envp[i] = ft_strjoin("PWD=", ptr);
	free(ptr);
}
