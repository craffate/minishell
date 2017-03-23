/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:39:07 by craffate          #+#    #+#             */
/*   Updated: 2017/03/23 17:36:41 by craffate         ###   ########.fr       */
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

static char	**envp_setup(char **ep)
{
	char			**envp;
	char			*t;
	unsigned int	i;

	i = 0;
	t = NULL;
	while (ep[i])
		i++;
	if (!(envp = (char **)malloc(sizeof(char *) * (i + 1))))
		error_handler(1);
	i = 0;
	while (ep[i])
	{
		if (!ft_strncmp(ep[i], "SHLVL=", 6) && (t = ft_itoa(envp_shlvl(ep[i]))))
		{
			envp[i++] = ft_strjoin("SHLVL=", t);
			free(t);
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
	char	*pwd;
	int		i;

	buf = NULL;
	argv = NULL;
	while ((i = get_next_line(0, &buf)))
	{
		if (i == -1)
			error_handler(2);
		if (*buf)
			argv = split_input(buf);
		if (*buf)
			free(buf);
		argv ? exec(argv, &envp) : 0;
		if (*argv)
			free_env(argv);
		pwd = pwd_print();
		ft_printf("{green}msh{eoc} - {yellow}%s{eoc} $> ", pwd);
		free(pwd);
	}
}

int			main(int ac, char **av, char **ep)
{
	char	**envp;
	char	*pwd;

	(void)ac;
	(void)av;
	signals();
	envp = envp_setup(ep);
	pwd = pwd_print();
	ft_printf("{green}msh{eoc} - {yellow}%s{eoc} $> ", pwd);
	loop(envp);
	free_env(envp);
	return (0);
}
