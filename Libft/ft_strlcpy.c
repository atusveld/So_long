/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:01:22 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 18:01:24 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return ((size_t)ft_strlen(src));
	while (src[i] && n - 1)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return ((size_t)ft_strlen(src));
}
