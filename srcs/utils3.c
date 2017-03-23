/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:06:43 by craffate          #+#    #+#             */
/*   Updated: 2017/03/23 18:13:08 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		cd_pchecker(const char *ptr)
{
	if (access(ptr, F_OK))
	{
		error_handler(9);
		return (-1);
	}
	if (access(ptr, R_OK))
	{
		error_handler(6);
		return (-1);
	}
	return (0);
}
