/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:01:11 by atusveld      #+#    #+#                 */
/*   Updated: 2022/08/03 16:36:54 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	ttll;
	size_t	ncpy;

	ncpy = n;
	ttll = ((size_t)ft_strlen(dest) + (size_t)ft_strlen(src));
	while (*dest && n > 0)
	{
		dest++;
		n--;
	}
	while (*src && n == 0)
		return ((size_t)ft_strlen(src) + ncpy);
	while (*src && n > 1)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (ttll);
}
