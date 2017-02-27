/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:02:48 by craffate          #+#    #+#             */
/*   Updated: 2017/02/15 18:06:41 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackrotate(t_stack *stack)
{
	int		i;
	size_t	j;

	if (stack->head < 2)
		return ;
	i = stack->data[stack->head - 1];
	j = stack->head - 1;
	while (j > 0)
	{
		stack->data[j] = stack->data[j - 1];
		j--;
	}
	stack->data[0] = i;
}
