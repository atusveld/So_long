/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:01:59 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:28:07 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *src, const char *dest, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) src;
	str2 = (unsigned char *) dest;
	while (*str1 && *str1 == *str2 && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return (*str1 - *str2);
}
