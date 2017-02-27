/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:06:22 by craffate          #+#    #+#             */
/*   Updated: 2017/02/24 10:07:07 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	unsigned int	i;
	long long int	j;
	int				k;

	i = 0;
	j = 0;
	k = 1;
	if (str[0] == '\0')
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		k = -1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
		j = j * 10 + str[i++] - '0';
	return (k * j);
}
