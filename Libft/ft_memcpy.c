/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:58:11 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:21:47 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		n--;
	}
	return (dest);
}
