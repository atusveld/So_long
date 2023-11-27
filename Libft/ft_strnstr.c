/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:02:26 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:16:08 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && n > 0)
	{
		i = 0;
		if (*haystack == needle[i])
		{
			while (haystack[i] == needle[i] && i < n)
			{
				i++;
				if (!needle[i])
					return ((char *)haystack);
			}
		}
		n--;
		haystack++;
	}
	return (NULL);
}
