/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:17:45 by craffate          #+#    #+#             */
/*   Updated: 2017/02/15 10:32:09 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		ft_stacknew(size_t size)
{
	t_stack		ret;

	if (!(ret.data = malloc(sizeof(int) * size)))
		exit(-1);
	ret.head = 0;
	ret.size = size;
	return (ret);
}
