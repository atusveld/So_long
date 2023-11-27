/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:01:44 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:17:05 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*nstr;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	nstr = (char *)malloc(i + 1);
	if (nstr == NULL)
		return (NULL);
	nstr[i] = '\0';
	while (i > 0)
	{
		i--;
		nstr[i] = f(i, str[i]);
	}
	return (nstr);
}
