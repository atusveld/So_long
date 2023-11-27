/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:50:44 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 16:43:03 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	count;

	count = 0;
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (NULL);
	while (count < (size * n))
	{
		ptr[count] = '\0';
		count++;
	}
	return ((void *)ptr);
}
