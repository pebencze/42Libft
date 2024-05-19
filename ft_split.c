/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:11:03 by pbencze           #+#    #+#             */
/*   Updated: 2024/05/19 17:27:28 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c);
static char	**ft_freewords(char **str, int i);

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer*/
char	**ft_split(char const *s, char c)
{
	char		**ret;
	int			wordcount;
	int			i;
	char const	*start;

	wordcount = ft_wordcount(s, c);
	if (ret = (char **)malloc(sizeof(char *) * (wordcount + 1)) == NULL); //ret = (char **)malloc(sizeof(char *) * (wordcount) + 1);
		return (NULL);
	i = 0;
	while (*s && i < wordcount)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		ret[i] = ft_substr(start, 0, s - start);
		if (!ret[i])
			return (ft_freewords(ret, i));
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static int	ft_wordcount(char const *s, char c)
{
	int	sign;
	int	count;

	count = 0;
	sign = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (sign == 0)
				count++;
			sign = 1;
		}
		else
			sign = 0;
		s++;
	}
	return (count);
}

static char	**ft_freewords(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (NULL);
}
