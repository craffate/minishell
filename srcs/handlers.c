/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:29:40 by craffate          #+#    #+#             */
/*   Updated: 2017/03/06 13:01:59 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	status_handler(int status)
{
	if (WIFSIGNALED(status))
		ft_printf("Process killed by signed %d", WTERMSIG(status));
	else if (WIFSTOPPED(status))
		ft_printf("Process stopped by signed %d", WSTOPSIG(status));
}

void	error_handler(int error)
{
	error == 1 ? write(2, MSH_MERROR, 24) : 0;
	error == 2 ? write(2, MSH_IERROR, 23) : 0;
	error == 3 ? write(2, MSH_FORKFAIL, 15) : 0;
	error == 4 ? write(2, MSH_UNKNOWNCMD, 16) : 0;
	error == 5 ? write(2, MSH_BINNOTFOUND, 22) : 0;
	error == 6 ? write(2, MSH_DENIED, 14) : 0;
	error == 7 ? write(2, MSH_INVALID, 15) : 0;
	error == 8 ? write(2, MSH_NOENV, 36) : 0;
	error == 9 ? write(2, MSH_NOPATH, 23) : 0;
	error == 10 ? write(2, MSH_NOPATH, 23) : 0;
	if (error == 1 || error == 2)
		exit(EXIT_FAILURE);
	else
		return ;
}
