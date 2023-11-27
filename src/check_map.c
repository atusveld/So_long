/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:44:11 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:22:19 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_sl *sl)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (sl->map[y] != NULL)
	{
		x = 0;
		while (sl->map[y][x] != '\0')
		{
			if (sl->map[y][x] == 'C')
				sl->tc += 1;
			if (sl->map[y][x] == 'P')
			{
				sl->x = x;
				sl->y = y;
			}
			x++;
		}
		y++;
	}
}
