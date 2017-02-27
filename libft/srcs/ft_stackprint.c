/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:24:00 by craffate          #+#    #+#             */
/*   Updated: 2017/02/15 10:35:15 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_stackprint(t_stack stack)
{
	while (stack.head--)
		ft_printf("%d\n", stack.data[stack.head]);
}
