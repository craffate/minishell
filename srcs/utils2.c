/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:37:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/05 17:38:47 by craffate         ###   ########.fr       */
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

char			*pwd_print(const char **envp)
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
