/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:19:19 by craffate          #+#    #+#             */
/*   Updated: 2017/02/15 10:32:23 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, int data)
{
	if (!(stack->head < stack->size))
		return ;
	stack->data[stack->head++] = data;
}
