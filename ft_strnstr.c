/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:33:00 by pbencze           #+#    #+#             */
/*   Updated: 2024/05/19 17:28:37 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && len >= ft_strlen(little))
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}
