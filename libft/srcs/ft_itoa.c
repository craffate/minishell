/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:52:03 by craffate          #+#    #+#             */
/*   Updated: 2017/03/15 08:09:55 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	getsize(long long int *n)
{
	unsigned int	si;
	long long int	n2;

	si = 1;
	if (*n < 0)
	{
		si++;
		*n *= -1;
	}
	n2 = *n;
	while (n2 /= 10)
		si++;
	return (si);
}

char				*ft_itoa(long long int n)
{
	unsigned int	si;
	char			*s;
	short			sign;

	if (!n)
		return (NULL);
	sign = n < 0 ? -1 : 0;
	si = getsize(&n);
	if (!(s = (char *)malloc(sizeof(char) * (si + 1))))
		return (NULL);
	s[si] = 0;
	while (si--)
	{
		s[si] = n % 10 + 48;
		n /= 10;
	}
	if (sign)
		*s = 45;
	return (s);
}
