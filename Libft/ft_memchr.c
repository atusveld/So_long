/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:57:48 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:22:39 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int chr, size_t n)
{
	unsigned char	*nstr;
	unsigned char	c;

	nstr = (unsigned char *) str;
	c = (unsigned char) chr;
	while (n > 0)
	{
		if (*nstr == c)
			return (nstr);
		nstr++;
		n--;
	}
	return (NULL);
}
