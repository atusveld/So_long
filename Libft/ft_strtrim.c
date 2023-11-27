/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:02:50 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 18:15:36 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;

	i = 0;
	if (str == NULL || set == NULL)
		return (NULL);
	while (ft_strlen(str) && ft_strchr(set, *str))
		str++;
	i = ft_strlen(str);
	while (ft_strlen(str) && ft_strchr(set, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
