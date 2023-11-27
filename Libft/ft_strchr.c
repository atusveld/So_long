/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:00:25 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:19:12 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (*str)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}
