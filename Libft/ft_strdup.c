/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:00:34 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:18:58 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strdup(const char *str)
{
	size_t			nbr;
	unsigned char	*src;
	unsigned char	*dest;

	src = (unsigned char *) str;
	nbr = ft_strlen(str) + 1;
	dest = (unsigned char *) ft_calloc(nbr, 1);
	if (dest == NULL)
		return (NULL);
	return ((char *) ft_memcpy(dest, src, nbr));
}
