/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:00:59 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/27 14:58:23 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_join_str(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	char	*nstr;

	i = 0;
	j = 0;
	nstr = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), 1);
	if (nstr == NULL)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		nstr[i] = str1[j];
		i++;
		j++;
	}
	j = 0;
	while (j < ft_strlen(str2))
	{
		nstr[i] = str2[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*nstr;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	nstr = ft_join_str(str1, str2);
	return (nstr);
}
