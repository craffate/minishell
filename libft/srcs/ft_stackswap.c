/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:22:19 by craffate          #+#    #+#             */
/*   Updated: 2017/02/15 10:23:48 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackswap(t_stack *stack)
{
	unsigned int	i;

	if (stack->head < 2)
		return ;
	i = stack->data[stack->head - 1];
	stack->data[stack->head - 1] = stack->data[stack->head - 2];
	stack->data[stack->head - 2] = i;
}
