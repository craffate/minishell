/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:43:03 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 15:22:59 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *s)
{
	long long int	j;
	short			k;

	if (!s)
		return (0);
	j = 0;
	k = 1;
	while (*s == '\v' || *s == '\t' || *s == '\f' || *s == '\r' ||
			*s == '\n' || *s == ' ')
		s++;
	if (*s == 45)
		k = -1;
	s += (*s == 45 || *s == 43) ? 1 : 0;
	while (*s > 47 && *s < 58)
		j = j * 10 + *s++ - 48;
	return (k * j);
}
