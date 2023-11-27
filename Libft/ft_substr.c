/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:03:01 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 17:07:58 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str))
		return (ft_strdup(str + start));
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (str && len)
	{
		substr[i] = str[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
