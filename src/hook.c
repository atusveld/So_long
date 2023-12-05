/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:57:39 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:19:14 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_close(param);
	else if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
		ft_update_player(sl, 0, -1);
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
		ft_update_player(sl, -1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
		ft_update_player(sl, 0, 1);
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
		ft_update_player(sl, 1, 0);
	else if (sl->map[sl->y][sl->x] == 'E' &&
		keydata.key == MLX_KEY_ENTER && keydata.action == MLX_PRESS)
	{
		if (sl->c == sl->tc)
			ft_close(NULL);
	}
}

void	ft_update_player(t_sl *sl, int x, int y)
{
	if (!(sl->map[sl->y + y][sl->x + x] == '1'))
	{
		mlx_image_to_window(sl->mlx, sl->sprt.playr,
			(((sl->x + x) * 32) + 4), (((sl->y + y) * 32) + 4));
		mlx_image_to_window(sl->mlx, sl->sprt.tile,
			(sl->x * 32), (sl->y * 32));
		if (sl->map[sl->y][sl->x] == 'E')
			mlx_image_to_window(sl->mlx, sl->sprt.exit,
				(sl->x * 32), (sl->y * 32));
		if (sl->map[sl->y][sl->x] == 'C')
			sl->c += 1;
		sl->st += 1;
		ft_putnbr_fd(sl->st, 1);
		ft_putchar_fd('\n', 1);
		sl->y += y;
		sl->x += x;
	}
}
