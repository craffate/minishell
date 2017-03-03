/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:39:07 by craffate          #+#    #+#             */
/*   Updated: 2017/03/03 15:06:36 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		envp_add(const char *var, char ***envp)
{
	char			**envp2;
	int				i;

	i = 0;
	while ((*envp)[i])
		i++;
	if (!(envp2 = (char **)malloc(sizeof(char *) * (i + 2))))
		error_handler(1);
	i = 0;
	while ((*envp)[i])
	{
		envp2[i] = ft_strdup((*envp)[i]);
		i++;
	}
	envp2[i++] = ft_strdup(var);
	envp2[i] = NULL;
	free_env(*envp);
	*envp = envp2;
}

static int	envp_shlvl(char *s)
{
	while (*s++)
		if (*(s - 1) == '=')
			break ;
	return (ft_atoi(s) + 1);
}

static char **envp_setup(char **ep)
{
	char			**envp;
	char			*tmp;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 7;
	tmp = NULL;
	while (ep[i])
		i++;
	if (!(envp = (char **)malloc(sizeof(char *) * (i + 1))))
		error_handler(1);
	i = 0;
	while (ep[i])
	{
		if (!ft_strncmp(ep[i], "SHLVL=", 6))
		{
			tmp = ft_itoa(envp_shlvl(ep[i]));
			envp[i++] = ft_strjoin("SHLVL=", tmp);
			free(tmp);
			tmp = NULL;
		}
		envp[i] = ft_strdup(ep[i]);
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

static void	loop(char **envp)
{
	char	*buf;
	char	**argv;
	int		i;

	buf = ft_strnew(0);
	argv = NULL;
	if (!buf)
		error_handler(1);
	while ((i = get_next_line(0, &buf)))
	{
		if (i == -1)
			error_handler(2);
		if (buf)
		{
			argv = split_input(buf);
			free(buf);
		}
		argv ? exec(argv, &envp) : 0;
		ft_printf("{green}msh{eoc} - {yellow}%s{eoc} $> ",
		pwd_print((const char **)envp));
	}
	free_env(envp);
}

int			main(int ac, char **av, char **ep)
{
	char	**envp;

	(void)ac;
	(void)av;
	envp = envp_setup(ep);
	ft_printf("{green}msh{eoc} - {yellow}%s{eoc} $> ",
	pwd_print((const char **)envp));
	loop(envp);
	return (0);
}
