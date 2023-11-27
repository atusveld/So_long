/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 18:00:09 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/27 14:57:33 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_freefail(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

static	int	ft_count_row(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			while (*str != c && *str)
			{
				str++;
			}
			count++;
		}
	}
	return (count);
}

static	void	ft_split_str(char **arr, char const *str, char c, int count)
{
	int	i;
	int	j;

	j = 0;
	while (j < count)
	{
		i = 0;
		while (*str == c && *str)
			str++;
		while (str[i] != c && str[i])
			i++;
		arr[j] = ft_substr(str, 0, i);
		if (arr[j] == NULL)
		{
			ft_freefail(arr);
			arr = 0;
			return ;
		}
		j++;
		str += i;
	}
}

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**arr;

	if (!str)
		return (NULL);
	count = ft_count_row(str, c);
	arr = (char **) malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr[count] = 0;
	ft_split_str(arr, str, c, count);
	return (arr);
}
