/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:20 by pbencze           #+#    #+#             */
/*   Updated: 2024/05/19 17:28:42 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ((int)ft_strlen(s));
	if (c == 0)
		return ((char *)&s[i]);
	while (i != 0 && s[i] != (unsigned char)c)
		i--;
	if ((unsigned char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
