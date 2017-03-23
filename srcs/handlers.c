/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:29:40 by craffate          #+#    #+#             */
/*   Updated: 2017/03/23 17:57:07 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
}

void	status_handler(int status)
{
	if (WIFSIGNALED(status))
		ft_printf("Process killed by signed %d", WTERMSIG(status));
	else if (WIFSTOPPED(status))
		ft_printf("Process stopped by signed %d", WSTOPSIG(status));
}

void	error_handler(const int error)
{
	error == 1 ? write(2, MSH_MERROR, ft_strlen(MSH_MERROR)) : 0;
	error == 2 ? write(2, MSH_IERROR, ft_strlen(MSH_IERROR)) : 0;
	error == 3 ? write(2, MSH_FORKFAIL, ft_strlen(MSH_FORKFAIL)) : 0;
	error == 4 ? write(2, MSH_UNKNOWNCMD, ft_strlen(MSH_UNKNOWNCMD)) : 0;
	error == 5 ? write(2, MSH_BINNOTFOUND, ft_strlen(MSH_BINNOTFOUND)) : 0;
	error == 6 ? write(2, MSH_DENIED, ft_strlen(MSH_DENIED)) : 0;
	error == 7 ? write(2, MSH_INVALID, ft_strlen(MSH_INVALID)) : 0;
	error == 8 ? write(2, MSH_NOENV, ft_strlen(MSH_NOENV)) : 0;
	error == 9 ? write(2, MSH_NOPATH, ft_strlen(MSH_NOPATH)) : 0;
	error == 10 ? write(2, MSH_NOHOME, ft_strlen(MSH_NOHOME)) : 0;
	error == 11 ? write(2, MSH_NOPWD, ft_strlen(MSH_NOPWD)) : 0;
	error == 12 ? write(2, MSH_NOOPWD, ft_strlen(MSH_NOOPWD)) : 0;
	if (error == 1)
		exit(EXIT_FAILURE);
	else
		return ;
}
