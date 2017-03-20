/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:37:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/20 16:17:39 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void			free_env(char **envp)
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

char			*pwd_print(void)
{
	char			buf[1024];
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	getcwd(buf, 1024);
	if (!(ft_strcmp(buf, "/")))
		return (ft_strdup("/"));
	ptr = buf + ft_strlen(buf);
	i = path_scan(buf);
	j = i > 1 ? 0 : 1;
	while (j != 2)
	{
		if (*ptr == 47)
			++j;
		--ptr;
	}
	ptr = ft_strdup(ptr + 2);
	return (ptr);
}

void			builtin_cd_chdir(char **ptr)
{
	chdir(*ptr);
	free(*ptr);
	*ptr = getcwd(NULL, MSH_BUFSIZE);
}
