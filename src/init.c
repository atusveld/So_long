/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:57:39 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:19:14 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_sl *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y] != NULL)
	{
		x = 0;
		while (sl->map[y][x] != '\0')
		{
			mlx_image_to_window(sl->mlx, sl->sprt.tile, (x * 32), (y * 32));
			if (sl->map[y][x] == '1')
				mlx_image_to_window(sl->mlx, sl->sprt.wall, (x * 32), (y * 32));
			if (sl->map[y][x] == 'C')
				mlx_image_to_window(sl->mlx, sl->sprt.cltbl,
					((x * 32) + 7), ((y * 32) + 7));
			if (sl->map[y][x] == 'E')
				mlx_image_to_window(sl->mlx, sl->sprt.exit, (x * 32), (y * 32));
			if (sl->map[y][x] == 'P')
				mlx_image_to_window(sl->mlx, sl->sprt.playr,
					((x * 32) + 4), ((y * 32) + 4));
			x++;
		}
		y++;
	}
}

mlx_image_t	*ft_tile_gen(mlx_t *mlx, int rgb, int x, int y)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, x, y);
	if (!img)
		ft_error(MLX);
	i = x;
	j = y;
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			mlx_put_pixel(img, (x), (y), rgb);
			y++;
		}
		x++;
	}
	return (img);
}

t_sprt	ft_init_sprites(mlx_t *mlx)
{
	t_sprt	tmp;

	tmp.tile = ft_tile_gen(mlx, 0x000000ff, 32, 32);
	tmp.wall = ft_tile_gen(mlx, 0x00ffffff, 32, 32);
	tmp.cltbl = ft_tile_gen(mlx, 0xf6d108ff, 18, 18);
	tmp.exit = ft_tile_gen(mlx, 0xff0000ff, 32, 32);
	tmp.playr = ft_tile_gen(mlx, 0x00ff00ff, 24, 24);
	return (tmp);
}

t_sl	ft_init_structs(mlx_t *mlx, char **map)
{
	t_sl	sl;

	sl.mlx = mlx;
	sl.sprt = ft_init_sprites(mlx);
	sl.map = map;
	sl.x = 0;
	sl.y = 0;
	sl.c = 0;
	sl.tc = 0;
	sl.fc = 0;
	sl.fe = 0;
	sl.st = 0;
	return (sl);
}

mlx_t	*ft_mlx_init(void)
{
	mlx_t			*mlx;

	mlx = mlx_init(1440, 1080, "So_long", false);
	if (!mlx)
		ft_error(MLX);
	return (mlx);
}
