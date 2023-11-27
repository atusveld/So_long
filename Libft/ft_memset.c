/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:58:36 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 17:58:38 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (n > i)
	{
		str[i] = c;
		i++;
	}
	return (b = str);
}
