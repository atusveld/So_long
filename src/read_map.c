/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:44:11 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:22:19 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_freefail_sl(char **arr)
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

static	int	ft_count_row_sl(char const *str, char c)
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
				str++;
			count++;
		}
	}
	return (count);
}

static	void	ft_split_str_sl(char **arr, char const *str, char c, int count)
{
	int	i;
	int	j;

	j = 0;
	while (j < count)
	{
		i = 0;
		if (*str == c && *str)
			str++;
		while (str[i] != c && str[i])
			i++;
		arr[j] = ft_substr(str, 0, i);
		if (arr[j] == NULL)
		{
			ft_freefail_sl(arr);
			arr = 0;
			return ;
		}
		j++;
		str += i;
	}
	if (*str != '\0')
		ft_error(MAP);
}

char	**ft_split_sl(char const *str, char c)
{
	int		count;
	char	**arr;

	if (!str)
		return (NULL);
	if (*str == c)
		ft_error(MAP);
	count = ft_count_row_sl(str, c);
	if (count == 0)
		ft_error(MAP);
	arr = (char **) malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr[count] = NULL;
	ft_split_str_sl(arr, str, c, count);
	return (arr);
}

char	**ft_read_map(char *map_name)
{
	int		fd;
	char	**map;
	char	*tmp;
	char	*map_str;
	char	buffer[2];

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(FDER);
	if (read(fd, buffer, 0) == -1)
		ft_error(MAP);
	map_str = ft_strdup("");
	while (read(fd, buffer, 1) == 1)
	{
		buffer[1] = '\0';
		tmp = map_str;
		map_str = ft_strjoin(map_str, buffer);
		if (tmp)
			free (tmp);
	}
	map = ft_split_sl(map_str, '\n');
	free (map_str);
	if (!map)
		ft_error(MAP);
	return (map);
}
