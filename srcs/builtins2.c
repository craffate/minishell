/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:08:48 by craffate          #+#    #+#             */
/*   Updated: 2017/03/04 12:56:46 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*builtin_setenv_setup(const char **argv)
{
	unsigned int	i;
	unsigned int	j;
	char			*ret;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char) *
	(ft_strlen(argv[1]) + ft_strlen(argv[2]) + 2))))
		error_handler(1);
	while (argv[1][i])
		ret[j++] = argv[1][i++];
	i = 0;
	ret[j++] = '=';
	while (argv[2][i])
		ret[j++] = argv[2][i++];
	ret[j] = 0;
	return (ret);
}

void		builtin_setenv(const char **argv, char ***envp)
{
	int				i;
	char			*tmp;

	if (!(*argv)[2])
		error_handler(7);
	i = find_env((const char **)*envp, argv[1]);
	tmp = builtin_setenv_setup(argv);
	if (i == -1)
		envp_add(tmp, envp);
	else
	{
		free((*envp)[i]);
		(*envp)[i] = ft_strdup(tmp);
	}
	free(tmp);
}

void		builtin_unsetenv(const char **argv, char ***envp)
{
	int				i;
	unsigned int	j;

	if (!(*argv)[2])
		error_handler(7);
	i = find_env((const char **)*envp, argv[1]);
	j = 0;
	if (i == -1)
	{
		error_handler(8);
		return ;
	}
	else
	{
		free((*envp)[i++]);
		while ((*envp)[i])
		{
			(*envp)[i - 1] = (*envp)[i];
			i++;
		}
		(*envp)[i - 1] = NULL;
	}
}