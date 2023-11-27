/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:58:20 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 18:08:24 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) src;
	str2 = (unsigned char *) dest;
	if ((!n) || (str1 == str2))
		return (dest);
	if (str2 < str1)
	{
		while (n > 0)
		{
			*str2 = *str1;
			str1++;
			str2++;
			n--;
		}
	}
	else
	{
		while (n--)
			str2[n] = str1[n];
	}
	return (dest);
}
