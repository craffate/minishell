/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:23:53 by craffate          #+#    #+#             */
/*   Updated: 2017/02/27 11:30:47 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *s, size_t size)
{
	size_t			s_len;
	char			*ret;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (s_len + size + 1))))
		return (NULL);
	ft_bzero(ret, s_len + size + 1);
	i = 0;
	while (i < s_len)
	{
		ret[i] = s[i];
		i++;
	}
	free(s);
	return (ret);
}
