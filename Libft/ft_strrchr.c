/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:02:40 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:15:53 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (i >= 0 && *str)
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
