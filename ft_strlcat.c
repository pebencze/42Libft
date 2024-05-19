/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:59:02 by pbencze           #+#    #+#             */
/*   Updated: 2024/05/19 17:28:10 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strlcpy() and strlcat() functions copy and concatenate strings re‐
spectively.  They are designed to be safer, more consistent, and less er‐
ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
tions, strlcpy() and strlcat() take the full size of the buffer (not just
the length) and guarantee to NUL-terminate the result (as long as size is
larger than 0 or, in the case of strlcat(), as long as there is at least
one byte free in dst).  Note that a byte for the NUL should be included
in size.  Also note that strlcpy() and strlcat() only operate on true “C”
strings.  This means that for strlcpy() src must be NUL-terminated and
for strlcat() both src and dst must be NUL-terminated.
The strlcat() function appends the NUL-terminated string src to the end
of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
nating the result.*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && (dst_size + i) < (size - 1))
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = '\0';
	}
	if (size > dst_size)
		return (src_size + dst_size);
	return (size + src_size);
}
