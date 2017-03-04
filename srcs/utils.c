/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:07:50 by craffate          #+#    #+#             */
/*   Updated: 2017/03/04 13:17:59 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		find_env(const char **envp, const char *env)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], env, ft_strlen(env)))
			return (i);
	return (-1);
}

int		isbuiltin(const char *s)
{
	return (!ft_strncmp(s, "exit", 4) || !ft_strncmp(s, "echo", 4) ||
			!ft_strncmp(s, "cd", 2) || !ft_strncmp(s, "setenv", 6) ||
			!ft_strncmp(s, "unsetenv", 8) || !ft_strncmp(s, "env", 3) ? 1 : 0);
}

char	*join_path(const char *s1, const char *s2)
{
	char			*ret;
	size_t			i;
	size_t			j;
	unsigned int	k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 2))))
	{
		write(2, MSH_MERROR, 24);
		exit(EXIT_FAILURE);
	}
	while (*s1)
		ret[k++] = *s1++;
	ret[k++] = '/';
	while (*s2)
		ret[k++] = *s2++;
	ret[k] = '\0';
	return (ret);
}

char	**split_path(const char **envp)
{
	char			**path;
	char			*buf;
	unsigned int	i;
	unsigned int	k;
	unsigned int	l;

	i = 0;
	k = 5;
	l = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	buf = ft_strnew(ft_strlen(envp[i]) - 5);
	while (envp[i][k])
		buf[l++] = envp[i][k++];
	path = ft_strsplit(buf, ':');
	free(buf);
	buf = NULL;
	return (path);
}

char	**split_input(const char *buf)
{
	char	**s;

	s = ft_strsplit(buf, ' ');
	return (s);
}

void	free_env(char **envp)
{
	unsigned int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		envp[i++] = NULL;
	}
	free(envp);
	envp = NULL;
}

unsigned int	path_scan(const char *path)
{
	unsigned int	i;
	
	i = 0;
	while (*path)
	{
		if (*path == '/')
			i++;
		path++;
	}
	return (i);
}

char	*pwd_print(const char **envp)
{
	int				i;
	unsigned int	j;
	unsigned int	k;
	char			*ptr;

	i = find_env(envp, "PWD=");
	if (ft_strlen(envp[i]) == 5)
		return ("/");
	ptr = (char *)envp[i] + ft_strlen(envp[i]);
	k = path_scan(envp[i] + 4);
	j = k > 1 ? 0 : 1;
	while (j != 2)
	{
		if (*ptr == '/')
			j++;
		ptr--;
	}
	return (ptr + 2);
}
