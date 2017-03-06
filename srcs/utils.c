/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:07:50 by craffate          #+#    #+#             */
/*   Updated: 2017/03/06 13:08:54 by craffate         ###   ########.fr       */
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
	int				i;
	unsigned int	k;
	unsigned int	l;

	k = 5;
	l = 0;
	i = find_env(envp, "PATH=");
	if (i == -1)
		return (NULL);
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
